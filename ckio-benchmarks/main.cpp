#include "iotest.decl.h"
#include <vector>
#include <time.h>
#include <assert.h>
#include <iostream>
CProxy_Main mainproxy;

class Main : public CBase_Main
{
  Main_SDAG_CODE

      CProxy_Test testers;
  int n;

  Ck::IO::Session session;
  Ck::IO::File f;

  size_t fileSize;
  int i;
  int iters;
  double allTimes[10];
  double avgTime;
  double avg1;
  double avg2;
  double avg3;

  double start_time;
  // clock_t start_time_clock;
  // clock_t stage3_start;
  // clock_t stage2_start;

  // double stage1_time;
  // double stage2_time;
  // double stage3_time;

  int numBufChares;
  int numBufRemaining;
  std::string filename;

public:
  Main(CkArgMsg *m)
  {
    numBufChares = atoi(m->argv[1]); // arg 1 = number of buffer chares

    fileSize = atoi(m->argv[2]) * 1024 * 1024; // file size = arg 2

    n = atoi(m->argv[3]); // arg 3 = number of readers

    iters = atoi(m->argv[4]); // arg 4 = number of test iterations

    std::string fn(m->argv[5]);
    filename = fn;

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

public:
  Test(Ck::IO::Session token, size_t bytesToRead)
  {
    CkCallback sessionEnd(CkIndex_Test::readDone(0), thisProxy[thisIndex]);
    try
    {
      dataBuffer = new char[bytesToRead];
    }
    catch (const std::bad_alloc &e)
    {
      CkPrintf("ERROR: Data buffer malloc of %zu bytes in Test chare %d failed.\n", bytesToRead, thisIndex);
      CkExit();
    }
    size = bytesToRead;
    Ck::IO::read(token, bytesToRead, bytesToRead * thisIndex, dataBuffer, sessionEnd);
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
