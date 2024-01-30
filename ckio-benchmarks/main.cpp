#include "iotest.decl.h"
#include <vector>

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
  double totalTP;
  double start_time;

  int numBufChares;
  int numBufRemaining;

public:
  Main(CkArgMsg *m)
  {
    numBufChares = atoi(m->argv[1]); // arg 1 = number of buffer chares
    numBufRemaining = numBufChares;
    fileSize = atoi(m->argv[2]) * 1024 * 1024; // file size = arg 2

    n = atoi(m->argv[3]); // arg 3 = number of readers

    iters = atoi(m->argv[4]); // arg 4 = number of test iterations
    mainproxy = thisProxy;
    totalTP = 0;
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

public:
  Test(Ck::IO::Session token, size_t bytesToRead)
  {
    CkCallback sessionEnd(CkIndex_Test::readDone(0), thisProxy);
    dataBuffer = (char *)malloc(bytesToRead);
    Ck::IO::read(token, bytesToRead, bytesToRead * thisIndex, dataBuffer, sessionEnd);
  }

  Test(CkMigrateMessage *m) {}

  void readDone(Ck::IO::ReadCompleteMsg *m)
  {
    CkCallback done(CkIndex_Main::test_read(0), mainproxy);
    free(dataBuffer);
    contribute(done);
  }
};

#include "iotest.def.h"
