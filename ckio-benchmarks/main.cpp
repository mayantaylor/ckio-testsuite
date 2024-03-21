#include "iotest.decl.h"
#include <vector>
#include <time.h>
#include <assert.h>
#include <iostream>

// MACRO TO RUN BG WORK CONCURRENTLY
#undef BG
CProxy_Main mainproxy;

class Main : public CBase_Main
{
  Main_SDAG_CODE CProxy_Test testers;
  CProxy_Background bg;
  int n;

  Ck::IO::Session session;
  Ck::IO::File f;

  size_t fileSize;
  int i;
  int iters;
  double allTimes[10];
  double bgTimes[10];

  double start_time;

  int numBufChares;
  int numBufRemaining;

  std::string filename;

public:
  Main(CkArgMsg *m)
  {
    numBufChares = atoi(m->argv[1]);                   // arg 1 = number of buffer chares
    fileSize = (size_t)atoi(m->argv[2]) * 1024 * 1024; // file size = arg 2

    n = atoi(m->argv[3]);     // arg 3 = number of readers
    iters = atoi(m->argv[4]); // arg 4 = number of test iterations

    std::string fn(m->argv[5]); // arg 5 = filename
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
    // do some dummy work
    while (!workDone)
    {
      double start = CkWallTimer();
      // inner loop approx 10 microseconds
      while (CkWallTimer() - start < 1 * 1e-3)
        ;
      totalTime += CkWallTimer() - start;
      CthYield();
    }
#ifdef BG
    CkCallback done(CkReductionTarget(Main, bgDone), mainproxy);
    contribute(sizeof(double), &totalTime, CkReduction::sum_double, done);
#endif
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
