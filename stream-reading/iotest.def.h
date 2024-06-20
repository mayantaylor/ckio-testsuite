
/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::run_3_closure : public SDAG::Closure {
      

      run_3_closure() {
        init();
      }
      run_3_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~run_3_closure() {
      }
      PUPable_decl(SINGLE_ARG(run_3_closure));
    };
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY

    struct Closure_Main::iterDone_8_closure : public SDAG::Closure {
      

      iterDone_8_closure() {
        init();
      }
      iterDone_8_closure(CkMigrateMessage*) {
        init();
      }
            void pup(PUP::er& __p) {
        packClosure(__p);
      }
      virtual ~iterDone_8_closure() {
      }
      PUPable_decl(SINGLE_ARG(iterDone_8_closure));
    };
#endif /* CK_TEMPLATES_ONLY */


/* ---------------- method closures -------------- */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void ready(Ck::IO::FileReadyMsg* impl_msg);
void run();
void start_read(Ck::IO::SessionReadyMsg* impl_msg);
void test_read(CkReductionMsg* impl_msg);
void closed(CkReductionMsg* impl_msg);
void sessionClosed(CkReductionMsg* impl_msg);
void iterDone();
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */
CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}
void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

// Entry point registration function
int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Main_CkArgMsg), CMessage_CkArgMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkArgMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  new (impl_obj_void) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ready(Ck::IO::FileReadyMsg* impl_msg);
 */
void CProxy_Main::ready(Ck::IO::FileReadyMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_ready_FileReadyMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_ready_FileReadyMsg() {
  int epidx = CkRegisterEp("ready(Ck::IO::FileReadyMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_ready_FileReadyMsg), Ck::IO::CMessage_FileReadyMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::FileReadyMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_ready_FileReadyMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->ready((Ck::IO::FileReadyMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run();
 */
void CProxy_Main::run(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_run_void() {
  int epidx = CkRegisterEp("run()",
      reinterpret_cast<CkCallFnPtr>(_call_run_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->_sdag_fnc_run();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::run_3_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void start_read(Ck::IO::SessionReadyMsg* impl_msg);
 */
void CProxy_Main::start_read(Ck::IO::SessionReadyMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_start_read_SessionReadyMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_start_read_SessionReadyMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_start_read_SessionReadyMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_start_read_SessionReadyMsg() {
  int epidx = CkRegisterEp("start_read(Ck::IO::SessionReadyMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_start_read_SessionReadyMsg), Ck::IO::CMessage_SessionReadyMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::SessionReadyMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_start_read_SessionReadyMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->start_read((Ck::IO::SessionReadyMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void test_read(CkReductionMsg* impl_msg);
 */
void CProxy_Main::test_read(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_test_read_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_test_read_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_test_read_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}
void CkIndex_Main::_call_redn_wrapper_test_read_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  impl_obj->test_read((CkReductionMsg*)impl_msg);
  
}


// Entry point registration function
int CkIndex_Main::reg_test_read_CkReductionMsg() {
  int epidx = CkRegisterEp("test_read(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_test_read_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}


// Redn wrapper registration function
int CkIndex_Main::reg_redn_wrapper_test_read_CkReductionMsg() {
  return CkRegisterEp("redn_wrapper_test_read(CkReductionMsg *impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_redn_wrapper_test_read_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
}

void CkIndex_Main::_call_test_read_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->test_read((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void closed(CkReductionMsg* impl_msg);
 */
void CProxy_Main::closed(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_closed_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_closed_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_closed_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_closed_CkReductionMsg() {
  int epidx = CkRegisterEp("closed(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_closed_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_closed_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->closed((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void sessionClosed(CkReductionMsg* impl_msg);
 */
void CProxy_Main::sessionClosed(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_sessionClosed_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_sessionClosed_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_sessionClosed_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_sessionClosed_CkReductionMsg() {
  int epidx = CkRegisterEp("sessionClosed(CkReductionMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_sessionClosed_CkReductionMsg), CMessage_CkReductionMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)CkReductionMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Main::_call_sessionClosed_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->sessionClosed((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void iterDone();
 */
void CProxy_Main::iterDone(const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg(impl_e_opts);
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_iterDone_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_iterDone_void(), impl_msg, &ckGetChareID(),destPE);
  } else {
    CkSendMsg(CkIndex_Main::idx_iterDone_void(), impl_msg, &ckGetChareID(),0);
  }
}

// Entry point registration function
int CkIndex_Main::reg_iterDone_void() {
  int epidx = CkRegisterEp("iterDone()",
      reinterpret_cast<CkCallFnPtr>(_call_iterDone_void), 0, __idx, 0);
  return epidx;
}

void CkIndex_Main::_call_iterDone_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*>(impl_obj_void);
  impl_obj->iterDone();
  if(UsrToEnv(impl_msg)->isVarSysMsg() == 0)
    CkFreeSysMsg(impl_msg);
}
PUPable_def(SINGLE_ARG(Closure_Main::iterDone_8_closure))
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void ready(Ck::IO::FileReadyMsg* impl_msg);
  idx_ready_FileReadyMsg();

  // REG: void run();
  idx_run_void();

  // REG: void start_read(Ck::IO::SessionReadyMsg* impl_msg);
  idx_start_read_SessionReadyMsg();

  // REG: void test_read(CkReductionMsg* impl_msg);
  idx_test_read_CkReductionMsg();
  idx_redn_wrapper_test_read_CkReductionMsg();

  // REG: void closed(CkReductionMsg* impl_msg);
  idx_closed_CkReductionMsg();

  // REG: void sessionClosed(CkReductionMsg* impl_msg);
  idx_sessionClosed_CkReductionMsg();

  // REG: void iterDone();
  idx_iterDone_void();

  Main::__sdag_register(); // Potentially missing Main_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Main::run(){
  CkPrintf("Error> Direct call to SDAG entry method \'%s::%s\'!\n", "Main", "run()"); 
  CkAbort("Direct SDAG call is not allowed for SDAG entry methods having when constructs. Call such SDAG methods using a proxy"); 
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_fnc_run() {
  _TRACE_END_EXECUTE(); 
  if (!__dep.get()) _sdag_init();
  _slist_0();
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::run_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0() {
  _serial_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0_end() {
  run_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_0() {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_0()), CkMyPe(), 0, NULL, this); 
  { // begin serial block
#line 11 "mini.ci"

        Ck::IO::Options opts;
        opts.numReaders = numBufChares;
        CkCallback opened(CkIndex_Main::ready(NULL), thisProxy);
        char name[50];
        strcpy(name, filename.c_str());
        CkPrintf("Starting timers and opening file: %s\n", name);
        start_time = CkWallTimer();
        Ck::IO::open(name, opened, opts);
      
#line 432 "iotest.def.h"
  } // end serial block
  _TRACE_END_EXECUTE(); 
  _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_0() {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(0, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_1(static_cast<Ck::IO::FileReadyMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(0);
    c->anyEntries.push_back(0);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_0_end(Ck::IO::FileReadyMsg* gen0) {
  {
    Ck::IO::FileReadyMsg*& m = gen0;
    CmiFree(UsrToEnv(m));
  }
  _when_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_1(Ck::IO::FileReadyMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_1()), CkMyPe(), 0, NULL, this); 
  {
    Ck::IO::FileReadyMsg*& m = gen0;
    { // begin serial block
#line 22 "mini.ci"

        f = m->file;
        CkCallback sessionStart(CkIndex_Main::start_read(0), thisProxy);
        Ck::IO::startReadSession(f, fileSize, 0, sessionStart);
        delete m;
      
#line 482 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_0_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_1() {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(1, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_2(static_cast<Ck::IO::SessionReadyMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(1);
    c->anyEntries.push_back(1);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_1_end(Ck::IO::SessionReadyMsg* gen0) {
  {
    Ck::IO::SessionReadyMsg*& m = gen0;
    CmiFree(UsrToEnv(m));
  }
  _when_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_2(Ck::IO::SessionReadyMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_2()), CkMyPe(), 0, NULL, this); 
  {
    Ck::IO::SessionReadyMsg*& m = gen0;
    { // begin serial block
#line 29 "mini.ci"

        size_t sizeToRead = fileSize / n;
        session = m->session;
        testers = CProxy_Test::ckNew(m->session, sizeToRead, readType, n);
      
#line 532 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_1_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_2() {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(2, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_3(static_cast<CkReductionMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(2);
    c->anyEntries.push_back(2);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_2_end(CkReductionMsg* gen0) {
  {
    CkReductionMsg*& m = gen0;
    CmiFree(UsrToEnv(m));
  }
  _when_3();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_3(CkReductionMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_3()), CkMyPe(), 0, NULL, this); 
  {
    CkReductionMsg*& m = gen0;
    { // begin serial block
#line 35 "mini.ci"

        totalTime = CkWallTimer() - start_time;
        CkCallback cb(CkIndex_Main::sessionClosed(0), thisProxy);
        Ck::IO::closeReadSession(session, cb);
        delete m;
      
#line 583 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_2_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_3() {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(3, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_4(static_cast<CkReductionMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(3);
    c->anyEntries.push_back(3);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_3_end(CkReductionMsg* gen0) {
  {
    CkReductionMsg*& m = gen0;
    CmiFree(UsrToEnv(m));
  }
  _when_4();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_4(CkReductionMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_4()), CkMyPe(), 0, NULL, this); 
  {
    CkReductionMsg*& m = gen0;
    { // begin serial block
#line 43 "mini.ci"

      CkPrintf("read session closed\n");
        CkCallback closedCb(CkIndex_Main::closed(0), thisProxy);
        Ck::IO::close(f, closedCb);
        testers.ckDestroy();
        delete m;
      
#line 635 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_3_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
SDAG::Continuation* Main::_when_4() {
  SDAG::Buffer* buf0 = __dep->tryFindMessage(4, false, 0, 0);
  if (buf0) {
    __dep->removeMessage(buf0);
    _serial_5(static_cast<CkReductionMsg*>(static_cast<SDAG::MsgClosure*>(buf0->cl)->msg));
    delete buf0;
    return 0;
  } else {
    SDAG::Continuation* c = new SDAG::Continuation(4);
    c->anyEntries.push_back(4);
    __dep->reg(c);
    return c;
  }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_4_end(CkReductionMsg* gen0) {
  {
    CkReductionMsg*& m = gen0;
    CmiFree(UsrToEnv(m));
  }
  _slist_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_serial_5(CkReductionMsg* gen0) {
  _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_serial_5()), CkMyPe(), 0, NULL, this); 
  {
    CkReductionMsg*& m = gen0;
    { // begin serial block
#line 52 "mini.ci"

      CkPrintf("file closed\n");
        delete m;
        CkPrintf("-----SUMMARY DATA------\n");
        CkPrintf("%d %d %d %d %llu %f\n",readType, n, numBufChares, CkNumPes(), fileSize / (1024 * 1024), totalTime);
        CkPrintf("-----END SUMMARY------\n");
        CkExit();
      
#line 688 "iotest.def.h"
    } // end serial block
  }
  _TRACE_END_EXECUTE(); 
  _when_4_end(gen0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::ready(Ck::IO::FileReadyMsg* m_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(m_msg);
  __dep->pushBuffer(0, new SDAG::MsgClosure(m_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(0);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_0(
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::start_read(Ck::IO::SessionReadyMsg* m_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(m_msg);
  __dep->pushBuffer(1, new SDAG::MsgClosure(m_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(1);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_1(
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::test_read(CkReductionMsg* m_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(m_msg);
  __dep->pushBuffer(2, new SDAG::MsgClosure(m_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(2);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_2(
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::sessionClosed(CkReductionMsg* m_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(m_msg);
  __dep->pushBuffer(3, new SDAG::MsgClosure(m_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(3);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_3(
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::closed(CkReductionMsg* m_msg){
  if (!__dep.get()) _sdag_init();
  CkReferenceMsg(m_msg);
  __dep->pushBuffer(4, new SDAG::MsgClosure(m_msg));
  SDAG::Continuation* c = __dep->tryFindContinuation(4);
  if (c) {
    _TRACE_END_EXECUTE(); 
    _when_4(
    );
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _sdagEP, CkMyPe(), 0, NULL, this); 
    delete c;
  }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_init() { // Potentially missing Main_SDAG_CODE in your class definition?
  __dep.reset(new SDAG::Dependency(5,5));
  __dep->addDepends(0,0);
  __dep->addDepends(1,1);
  __dep->addDepends(2,2);
  __dep->addDepends(3,3);
  __dep->addDepends(4,4);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_init() { // Potentially missing Main_SDAG_CODE in your class definition?
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_sdag_pup(PUP::er &p) {  // Potentially missing Main_SDAG_CODE in your class definition?
  p|__dep;
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_register() { // Potentially missing Main_SDAG_CODE in your class definition?
  (void)_sdag_idx_Main_serial_0();
  (void)_sdag_idx_Main_serial_1();
  (void)_sdag_idx_Main_serial_2();
  (void)_sdag_idx_Main_serial_3();
  (void)_sdag_idx_Main_serial_4();
  (void)_sdag_idx_Main_serial_5();
  PUPable_reg(SINGLE_ARG(Closure_Main::run_3_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::iterDone_8_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::run_3_closure));
  PUPable_reg(SINGLE_ARG(Closure_Main::iterDone_8_closure));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_0() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_0() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_0", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_1() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_1() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_1", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_2() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_2() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_2", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_3() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_3();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_3() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_3", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_4() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_4();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_4() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_4", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_serial_5() { // Potentially missing Main_SDAG_CODE in your class definition?
  static int epidx = _sdag_reg_Main_serial_5();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_serial_5() { // Potentially missing Main_SDAG_CODE in your class definition?
  return CkRegisterEp("Main_serial_5", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: array Test: ArrayElement{
Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
Test(CkMigrateMessage* impl_msg);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Test::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CProxySection_Test::contribute(CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, userData, fragSize);
}

void CProxySection_Test::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, userData, fragSize);
}

template <typename T>
void CProxySection_Test::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, userData, fragSize);
}

void CProxySection_Test::contribute(CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(sid, cb, userData, fragSize);
}

void CProxySection_Test::contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(dataSize, data, type, sid, cb, userData, fragSize);
}

template <typename T>
void CProxySection_Test::contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData, int fragSize)
{
   CkArray *ckarr = CProxy_CkArray(sid.get_aid()).ckLocalBranch();
   CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(ckarr->getmCastMgr()).ckLocalBranch();
   mCastGrp->contribute(data, type, sid, cb, userData, fragSize);
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
 */
void CProxyElement_Test::insert(const Ck::IO::Session &token, const size_t &bytesToRead, int readType, int onPE, const CkEntryOptions *impl_e_opts)
{ 
   //Marshall: const Ck::IO::Session &token, const size_t &bytesToRead, int readType
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
  }
   UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Test::idx_Test_marshall1(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxyElement_Test::readDone(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Test::idx_readDone_ReadCompleteMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
 */
CkArrayID CProxy_Test::ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, int readType, const CkArrayOptions &opts, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &token, const size_t &bytesToRead, int readType
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Test::idx_Test_marshall1(), opts);
  return gId;
}
void CProxy_Test::ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, int readType, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &token, const size_t &bytesToRead, int readType
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
  }
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Test::idx_Test_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}
CkArrayID CProxy_Test::ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, int readType, const int s1, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &token, const size_t &bytesToRead, int readType
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkArrayID gId = ckCreateArray((CkArrayMessage *)impl_msg, CkIndex_Test::idx_Test_marshall1(), opts);
  return gId;
}
void CProxy_Test::ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, int readType, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts)
{
  //Marshall: const Ck::IO::Session &token, const size_t &bytesToRead, int readType
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<Ck::IO::Session>::type>::type &)token;
    //Have to cast away const-ness to get pup routine
    implP|(typename std::remove_cv<typename std::remove_reference<size_t>::type>::type &)bytesToRead;
    implP|readType;
  }
  CkArrayOptions opts(s1);
  UsrToEnv(impl_msg)->setMsgtype(ArrayEltInitMsg);
  CkSendAsyncCreateArray(CkIndex_Test::idx_Test_marshall1(), _ck_array_creation_cb, opts, impl_msg);
}

// Entry point registration function
int CkIndex_Test::reg_Test_marshall1() {
  int epidx = CkRegisterEp("Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType)",
      reinterpret_cast<CkCallFnPtr>(_call_Test_marshall1), CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_Test_marshall1);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_Test_marshall1);

  return epidx;
}

void CkIndex_Test::_call_Test_marshall1(void* impl_msg, void* impl_obj_void)
{
  Test* impl_obj = static_cast<Test*>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const Ck::IO::Session &token, const size_t &bytesToRead, int readType*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> token;
  implP|token;
  PUP::detail::TemporaryObjectHolder<size_t> bytesToRead;
  implP|bytesToRead;
  PUP::detail::TemporaryObjectHolder<int> readType;
  implP|readType;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Test(std::move(token.t), std::move(bytesToRead.t), std::move(readType.t));
}
int CkIndex_Test::_callmarshall_Test_marshall1(char* impl_buf, void* impl_obj_void) {
  Test* impl_obj = static_cast<Test*>(impl_obj_void);
  envelope *env = UsrToEnv(impl_buf);
  /*Unmarshall pup'd fields: const Ck::IO::Session &token, const size_t &bytesToRead, int readType*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> token;
  implP|token;
  PUP::detail::TemporaryObjectHolder<size_t> bytesToRead;
  implP|bytesToRead;
  PUP::detail::TemporaryObjectHolder<int> readType;
  implP|readType;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  new (impl_obj_void) Test(std::move(token.t), std::move(bytesToRead.t), std::move(readType.t));
  return implP.size();
}
void CkIndex_Test::_marshallmessagepup_Test_marshall1(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  envelope *env = UsrToEnv(impl_msg_typed);
  /*Unmarshall pup'd fields: const Ck::IO::Session &token, const size_t &bytesToRead, int readType*/
  PUP::fromMem implP(impl_buf);
  PUP::detail::TemporaryObjectHolder<Ck::IO::Session> token;
  implP|token;
  PUP::detail::TemporaryObjectHolder<size_t> bytesToRead;
  implP|bytesToRead;
  PUP::detail::TemporaryObjectHolder<int> readType;
  implP|readType;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("token");
  implDestP|token;
  if (implDestP.hasComments()) implDestP.comment("bytesToRead");
  implDestP|bytesToRead;
  if (implDestP.hasComments()) implDestP.comment("readType");
  implDestP|readType;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxy_Test::readDone(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Test::idx_readDone_ReadCompleteMsg(),0);
}

// Entry point registration function
int CkIndex_Test::reg_readDone_ReadCompleteMsg() {
  int epidx = CkRegisterEp("readDone(Ck::IO::ReadCompleteMsg* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_readDone_ReadCompleteMsg), Ck::IO::CMessage_ReadCompleteMsg::__idx, __idx, 0);
  CkRegisterMessagePupFn(epidx, (CkMessagePupFn)Ck::IO::ReadCompleteMsg::ckDebugPup);
  return epidx;
}

void CkIndex_Test::_call_readDone_ReadCompleteMsg(void* impl_msg, void* impl_obj_void)
{
  Test* impl_obj = static_cast<Test*>(impl_obj_void);
  impl_obj->readDone((Ck::IO::ReadCompleteMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(CkMigrateMessage* impl_msg);
 */

// Entry point registration function
int CkIndex_Test::reg_Test_CkMigrateMessage() {
  int epidx = CkRegisterEp("Test(CkMigrateMessage* impl_msg)",
      reinterpret_cast<CkCallFnPtr>(_call_Test_CkMigrateMessage), 0, __idx, 0);
  return epidx;
}

void CkIndex_Test::_call_Test_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  call_migration_constructor<Test> c = impl_obj_void;
  c((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
void CProxySection_Test::readDone(Ck::IO::ReadCompleteMsg* impl_msg) 
{
  ckCheck();
  UsrToEnv(impl_msg)->setMsgtype(ForArrayEltMsg);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Test::idx_readDone_ReadCompleteMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Test(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Test::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterArrayDimensions(__idx, 1);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
  idx_Test_marshall1();

  // REG: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
  idx_readDone_ReadCompleteMsg();

  // REG: Test(CkMigrateMessage* impl_msg);
  idx_Test_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Test_CkMigrateMessage());

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registeriotest(void)
{
  static int _done = 0; if(_done) return; _done = 1;

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void ready(Ck::IO::FileReadyMsg* impl_msg);
void run();
void start_read(Ck::IO::SessionReadyMsg* impl_msg);
void test_read(CkReductionMsg* impl_msg);
void closed(CkReductionMsg* impl_msg);
void sessionClosed(CkReductionMsg* impl_msg);
void iterDone();
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Test: ArrayElement{
Test(const Ck::IO::Session &token, const size_t &bytesToRead, int readType);
void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
Test(CkMigrateMessage* impl_msg);
};
*/
  CkIndex_Test::__register("Test", sizeof(Test));

}
extern "C" void CkRegisterMainModule(void) {
  _registeriotest();
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Main::virtual_pup(PUP::er &p) {
    recursive_pup<Main>(dynamic_cast<Main*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
template <>
void CBase_Test::virtual_pup(PUP::er &p) {
    recursive_pup<Test>(dynamic_cast<Test*>(this), p);
}
#endif /* CK_TEMPLATES_ONLY */
