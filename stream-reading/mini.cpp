#include "iotest.decl.h"
#include <vector>
#include <time.h>
#include <assert.h>
#include <iostream>

#include <fstream>

CProxy_Main mainproxy;
std::string filename;
std::string filename2;

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


public:
  Main(CkArgMsg *m)
  {
    numBufChares = atoi(m->argv[1]);                   // arg 1 = number of buffer chares
    fileSize = (size_t)atoi(m->argv[2]) * 1024 * 1024; // file size = arg 2
    n = atoi(m->argv[3]);                              // arg 3 = number of readers
    std::string fn(m->argv[4]);                        // arg 4 = filename
    std::string fn2(m->argv[5]);                        // arg 4 = filename


    filename = fn;
    filename2 = fn2;

    CkPrintf("done parsing args, starting prog\n");
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
  Test(Ck::IO::Session token, size_t bytesToRead)
  {

    CkCallback done(CkIndex_Main::test_read(0), mainproxy);
    char *dataBuffer2;
    try
    {
      dataBuffer = new char[bytesToRead];
      dataBuffer2 = new char[bytesToRead];
    }
    catch (const std::bad_alloc &e)
    {
      CkPrintf("ERROR: Data buffer malloc of %zu bytes in Test chare %d failed.\n", bytesToRead, thisIndex);
      CkExit();
    }


    
    // filereader streaming
    size = bytesToRead;
    Ck::IO::FileReader fr(token);
    fr.seekg(bytesToRead * thisIndex);  // seek to the correct place in the file
    size_t have_read=0;

    double frtimeavg = 0;
    int timeIdx = 0;
    size_t itersize=size;    
    while (have_read < size) {
      double start = CkWallTimer();
      fr.read(dataBuffer + have_read,
           itersize);  // hopefully this will return the same data as Ck::IO::read
      have_read+=itersize;
      frtimeavg += CkWallTimer() - start;
      timeIdx++;
    }

    frtimeavg = frtimeavg;    
   
    CkAssert(fr.gcount() == size);

    
    // ifstream streaming
    // std::ifstream rfile;
    // rfile.open(filename2);
    // if (rfile.is_open()) {
    //   rfile.seekg(bytesToRead * thisIndex);

    //   double ifsavg = 0;
    //   int count = 0;
    //   have_read = 0;
    //   while (have_read < size) {
    // 	double start = CkWallTimer();
    // 	rfile.read(dataBuffer2 + have_read, itersize);
    // 	have_read += itersize;
	
    // 	ifsavg += CkWallTimer() - start;
    // 	count++;
    //   }
    //   rfile.close();

    //   CkPrintf("Ifstream total time = %f, filereader total time = %f for %d read calls\n", ifsavg, frtimeavg, count);
    // }


    
    contribute(done);
  }

  Test(CkMigrateMessage *m) {}

  void readDone(Ck::IO::ReadCompleteMsg *m)
  {


    assert(dataBuffer[0] == 'a');
    assert(dataBuffer[size - 1] == 'a');

    free(dataBuffer);

  }
};

#include "iotest.def.h"
