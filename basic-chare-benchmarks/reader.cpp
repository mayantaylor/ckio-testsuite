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
   
class Main : public CBase_Main
{
  Main_SDAG_CODE
  CProxy_Reader reader;
  int i; 
  clock_t all_start;
  clock_t all_stop;

  double avg_total;
  double avg_min;
  double avg_max;
  
public:
    Main(CkArgMsg *msg)
    {
        if (msg->argc != 4)
        {
            CkPrintf("<Main> %s: expecting three arguments:\n\t<N> number of chares\n\t<K> input file size (GB)\t<F> filename\n",
                     msg->argv[0]);
            CkExit();
        }

        numChares = atoi(msg->argv[1]);
        fileSize = (size_t) atoi(msg->argv[2]) * 1024 * 1024;
        std::string fn(msg->argv[3]);
        filename = fn;

        allocFloor = (size_t) (fileSize / (double)numChares);
        mainProxy = thisProxy;

	avg_total = 0;
	avg_min = 0;
	avg_max = 0;
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
      if (thisIndex < numOverflow) {
	my_buffer_size = allocFloor + 1;
	offset = (size_t) thisIndex * (allocFloor + 1);
      }
      else {
	my_buffer_size = allocFloor;
	offset = (size_t) numOverflow * (allocFloor + 1) + (thisIndex - numOverflow) * allocFloor;
      }

      CkPrintf("Chare %d on PE %d.\n", thisIndex, CkMyPe());
      // setup buffer to read to
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
	if (lseek64(fd, offset, SEEK_SET) == -1) {
	  CkPrintf("<Reader> Lseek failed.\n");
	}

        // read allocation
	ssize_t bytes_read;
        clock_t start_time = clock();
	bytes_read = read(fd, buffer, my_buffer_size);
	clock_t end_time = clock();

	double read_time = (double) (end_time - start_time) / CLOCKS_PER_SEC * 1000;

	if (bytes_read != my_buffer_size)
	  {
	    CkPrintf("<Reader> Error: read failed - bytes read = %zu and bytes expected = %zu.\n",bytes_read, my_buffer_size);
	    CkExit();
	  }
	// CkPrintf("Read %d bytes in %f milliseconds\n", bytes_read, read_time);
	
	// close file and cleanup
	close(fd);

	free(buffer);

	double done_time = (double) clock();


	// contribute result to reductions
         CkCallback doneCb(CkReductionTarget(Main, doneReduction), mainProxy);
        contribute(sizeof(double), &done_time, CkReduction::max_double, doneCb);

        CkCallback maxCb(CkReductionTarget(Main, maxReduction), mainProxy);
        contribute(sizeof(double), &read_time, CkReduction::max_double, maxCb);

	CkCallback minCb(CkReductionTarget(Main, minReduction), mainProxy);
	contribute(sizeof(double), &read_time, CkReduction::min_double, minCb);
    }
};

#include "reader.def.h"
