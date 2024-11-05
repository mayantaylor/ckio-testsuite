#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include <unistd.h>
#include <fcntl.h>
#include <time.h>

// Error-checking macro
#define MPI_CHECK(call)                                           \
  if (call != MPI_SUCCESS)                                        \
  {                                                               \
    fprintf(stderr, "MPI error at %s:%d.\n", __FILE__, __LINE__); \
    MPI_Abort(MPI_COMM_WORLD, -1);                                \
  }

int main(int argc, char **argv)
{

  MPI_Init(&argc, &argv);
  MPI_Barrier(MPI_COMM_WORLD);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  double time;
  size_t fileSize = 1024 * 1024 * atoi(argv[1]);

  char filename[50];
  sprintf(filename, "%s", argv[2]);

  char *output_file = argv[3];

  MPI_File fh;
  double all_time = MPI_Wtime();
  MPI_CHECK(MPI_File_open(MPI_COMM_WORLD, filename, MPI_MODE_RDONLY, MPI_INFO_NULL, &fh));

  size_t mySize = fileSize / size;
  char *buffer = (char *)malloc(mySize);

  // // seek to start
  int start_pos = rank * mySize;
  MPI_CHECK(MPI_File_set_view(fh, start_pos, MPI_CHAR, MPI_CHAR, "native", MPI_INFO_NULL));

  // // read allocation
  double start = MPI_Wtime();
  MPI_Status status;
  MPI_File_read_all(fh, buffer, mySize, MPI_CHAR, &status);
  double end = MPI_Wtime();

  int read_count;
  MPI_Get_count(&status, MPI_CHAR, &read_count);
  if (read_count != mySize)
  {
    printf("Something failed on rank %d. Bytes read = %d\n", rank, read_count);
    return 1;
  }

  float myMillisec = (end - start) * 1000;

  // cleanup
  free(buffer);

  // contribute
  float global_min;
  float global_max;
  float global_sum;
  MPI_CHECK(MPI_Reduce(&myMillisec, &global_min, 1, MPI_FLOAT, MPI_MIN, 0, MPI_COMM_WORLD));
  MPI_CHECK(MPI_Reduce(&myMillisec, &global_max, 1, MPI_FLOAT, MPI_MAX, 0, MPI_COMM_WORLD));
  MPI_CHECK(MPI_Reduce(&myMillisec, &global_sum, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD));

  MPI_File_close(&fh);

  if (rank == 0)
  {
    double endall = MPI_Wtime();
    float total_time = (endall - all_time) * 1000;
    time = total_time;
    printf("Total time with %d procs: %f ms\n.", size, total_time);
    printf("Time spent in read(): min=%f, max=%f, avg=%f\n", global_min, global_max, global_sum / size);
  }

  if (rank == 0)
  {

    // write to output file
    int fd;
    int saved_stdout = dup(1);

    fd = open(output_file, O_WRONLY | O_APPEND, 0644);
    if (fd == -1)
    {
      printf("Open output file failed\n");
      return 1;
    }

    if (dup2(fd, 1) == -1)
    {
      printf("Dup2 failed to send output to outputfile\n");
      return 1;
    }

    printf("%d %d %f\n", size, atoi(argv[1]), time / 1000);

    close(fd);
    // restoring stdout

    dup2(saved_stdout, 1);
    close(saved_stdout);
  }

  MPI_Finalize();
  return 0;
}
