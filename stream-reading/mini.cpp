#include "iotest.decl.h"
#include <vector>
#include <time.h>
#include <assert.h>
#include <iostream>

#include <fstream>

CProxy_Main mainproxy;
std::string filename;
std::string filename2;
size_t itersize;

class Main : public CBase_Main
{
  Main_SDAG_CODE CProxy_Test testers;

  int n;

  Ck::IO::Session session;
  Ck::IO::File f;

  size_t fileSize;
  double totalTime;
  double bgTime;

  double start_time;
  int numBufChares;
  int readType;

  
public:
  Main(CkArgMsg *m)
  {
    numBufChares = atoi(m->argv[1]);                   // arg 1 = number of buffer chares
    fileSize = (size_t)atoi(m->argv[2]) * 1024 * 1024; // file size = arg 2
    n = atoi(m->argv[3]);                              // arg 3 = number of readers
    std::string fn(m->argv[4]);                        // arg 4 = filename
    readType = atoi(m->argv[5]);                        // arg 4 = filename

    
    itersize = (size_t) atoi(m->argv[6]);


    
    filename = fn;
  

    CkPrintf("done parsing args, starting prog with readType %d, itersize %llu\n", readType, itersize);
    mainproxy = thisProxy;
    thisProxy.run(); // open files
    delete m;
  }

  void iterDone()
  {
    CkExit();
  }
};


class Test : public CBase_Test
{
  char *dataBuffer;
  int size;
  bool workDone = false;

public:
  Test(Ck::IO::Session token, size_t bytesToRead, int readType)
  {

    size_t itersize = 32;

    try
    {
      dataBuffer = new char[bytesToRead];
      //dataBuffer2 = new char[bytesToRead];
    }
    catch (const std::bad_alloc &e)      {
      CkPrintf("ERROR: Data buffer malloc of %zu bytes in Test chare %d failed.\n", bytesToRead, thisIndex);
      CkExit();
    }
    
    // filereader streaming
    size = bytesToRead;

    if (readType == 0) {

      Ck::IO::FileReader fr(token);
       
       fr.seekg(bytesToRead * thisIndex);  // seek to the correct place in the file
       size_t have_read=0;


       while (have_read < size) {
     	double start = CkWallTimer();
     	fr.read(dataBuffer + have_read,
     		itersize);  // hopefully this will return the same data as Ck::IO::read
     	have_read+=itersize;

       }
 
       assert(dataBuffer[0] == 'a');
       assert(dataBuffer[size - 1] == 'a');

       CkCallback done(CkIndex_Main::test_read(0), mainproxy);
       contribute(done);
      
    }

    
    else if (readType == 1) {

      CkCallback sessionEnd(CkIndex_Test::readDone(0), thisProxy[thisIndex]);
      Ck::IO::read(token, bytesToRead, bytesToRead * thisIndex, dataBuffer, sessionEnd);
    }
    
    else if (readType == 2) {
      FILE* filePointer;
      filePointer = fopen(filename.c_str(), "r");
      size_t num_bytes_read = fread(dataBuffer, sizeof(char), bytesToRead, filePointer);
      fclose(filePointer);
      
      assert(dataBuffer[0] == 'a');
      assert(dataBuffer[size - 1] == 'a');
      CkCallback done(CkIndex_Main::test_read(0), mainproxy);
      contribute(done);


    }

    else {
      std::ifstream fr;
      fr.open(filename);

      fr.seekg(bytesToRead * thisIndex);  // seek to the correct place in the file
      size_t have_read=0;

      double frtimeavg = 0;
      int timeIdx = 0;

      while (have_read < size) {
	double start = CkWallTimer();
	fr.read(dataBuffer + have_read,
		itersize);  // hopefully this will return the same data as Ck::IO::read
	have_read+=itersize;
      }

      fr.close();

      assert(dataBuffer[0] == 'a');
      assert(dataBuffer[size - 1] == 'a');
      
      CkCallback done(CkIndex_Main::test_read(0), mainproxy);
      contribute(done);

    }



  }

  Test(CkMigrateMessage *m) {}

  void readDone(Ck::IO::ReadCompleteMsg *m)
  {

    CkCallback done(CkIndex_Main::test_read(0), mainproxy);
    
    assert(dataBuffer[0] == 'a');
    assert(dataBuffer[size - 1] == 'a');

    free(dataBuffer);
    contribute(done);

  }
};

#include "iotest.def.h"
