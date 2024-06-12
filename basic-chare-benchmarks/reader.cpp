#include <fstream>

#include "reader.decl.h"

#include <unistd.h>
#include <fcntl.h>

#include <string.h>
#include <errno.h>
#include <time.h>

/*readonly*/ int numChares;
/*readonly*/ size_t fileSize; // in bytes
/*readonly*/ std::string filename;
/*readonly*/ size_t allocFloor; // size of chare allocation (floor)
/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ int bg_on;

class Main : public CBase_Main
{
  Main_SDAG_CODE
      CProxy_Reader reader;
  int i;
  CProxy_Background bg;

  double all_start;
  double all_time;

public:
  Main(CkArgMsg *msg)
  {
    if (msg->argc != 5)
    {
      CkPrintf("<Main> %s: expecting four arguments:\n\t<N> number of chares\n\t<K> input file size (GB)\t<F> filename \t<B> background work boolean\n",
               msg->argv[0]);
      CkExit();
    }

    numChares = atoi(msg->argv[1]);
    fileSize = (size_t)atoi(msg->argv[2]) * 1024 * 1024;
    std::string fn(msg->argv[3]);
    filename = fn;

    bg_on = atoi(msg->argv[4]);

    allocFloor = (size_t)(fileSize / (double)numChares);
    mainProxy = thisProxy;

    thisProxy.run();
  }
};

class Reader : public CBase_Reader
{
private:
  size_t offset;
  size_t my_buffer_size;
  char *buffer;

public:
  Reader()
  {
    // compute size to read and setup buffer
    int numOverflow = fileSize % numChares;
    if (thisIndex < numOverflow)
    {
      my_buffer_size = allocFloor + 1;
      offset = (size_t)thisIndex * (allocFloor + 1);
    }
    else
    {
      my_buffer_size = allocFloor;
      offset = (size_t)numOverflow * (allocFloor + 1) + (thisIndex - numOverflow) * allocFloor;
    }

    // CkPrintf("Chare %d on PE %d.\n", thisIndex, CkMyPe());
    //  setup buffer to read to
    buffer = (char *)malloc(my_buffer_size);
    if (buffer == NULL)
    {
      CkPrintf("<Reader> Error: cannot allocate buffer.\n");
      CkExit();
    }
  }

  void readFile(std::string filename)
  {
    // open file for reading
    int fd = open64(filename.c_str(), O_RDONLY);
    if (fd == -1)
    {
      CkPrintf("<Reader> Error: cannot open file \"%s\"\n", filename.c_str());
      CkExit();
    }

    // seek to start of section
    if (lseek64(fd, offset, SEEK_SET) == -1)
    {
      CkPrintf("<Reader> Lseek failed.\n");
    }

    // read allocation
    ssize_t bytes_read;
    double start_time = CkWallTimer();
    bytes_read = read(fd, buffer, my_buffer_size);
    double end_time = CkWallTimer();

    double read_time = (end_time - start_time);

    if (bytes_read != my_buffer_size)
    {
      CkPrintf("<Reader> Error: read failed - bytes read = %zu and bytes expected = %zu.\n", bytes_read, my_buffer_size);
      CkExit();
    }
    // CkPrintf("Read %d bytes in %f milliseconds\n", bytes_read, read_time);

    // close file and cleanup
    close(fd);

    free(buffer);

    CkCallback maxCb(CkReductionTarget(Main, maxReduction), mainProxy);
    contribute(sizeof(double), &read_time, CkReduction::max_double, maxCb);

    CkCallback minCb(CkReductionTarget(Main, minReduction), mainProxy);
    contribute(sizeof(double), &read_time, CkReduction::min_double, minCb);
  }
};

class Background : public CBase_Background
{
private:
  bool workDone;

public:
  Background()
  {
    workDone = false;
    thisProxy[thisIndex].dummyBackgroundWork();
  }
  void setWorkDone()
  {
    workDone = true;
  }

  void dummyBackgroundWork() // threaded entry method
  {
    int dummyCounter = 10;
    double totalTime = 0;

    // do some dummy work for 1000 iterations
    int iter = 0;
    while (iter < 500)
    {
      double start = CkWallTimer();
      // inner loop approx 10 microseconds
      while (CkWallTimer() - start < 1 * 1e-3)
        ;
      totalTime += CkWallTimer() - start;
      CthYield();
      iter++;
    }

    CkCallback done(CkReductionTarget(Main, bgDone), mainProxy);
    contribute(sizeof(double), &totalTime, CkReduction::sum_double, done);
  }
};

#include "reader.def.h"
