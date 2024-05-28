#ifndef _DECL_iotest_H_
#define _DECL_iotest_H_
#include "charm++.h"
#include "envelope.h"
#include <memory>
#include "sdag.h"
#include "ckio.h"

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void ready(Ck::IO::FileReadyMsg* impl_msg);
void run();
void start_read(Ck::IO::SessionReadyMsg* impl_msg);
void test_read(CkReductionMsg* impl_msg);
void closed(CkReductionMsg* impl_msg);
void sessionClosed(CkReductionMsg* impl_msg);
void iterDone();
void bgDone(double time);
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CkIndex_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void ready(Ck::IO::FileReadyMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_ready_FileReadyMsg();
    // Entry point index lookup
    
    inline static int idx_ready_FileReadyMsg() {
      static int epidx = reg_ready_FileReadyMsg();
      return epidx;
    }

    
    inline static int idx_ready(void (Main::*)(Ck::IO::FileReadyMsg* impl_msg) ) {
      return idx_ready_FileReadyMsg();
    }


    
    static int ready(Ck::IO::FileReadyMsg* impl_msg) { return idx_ready_FileReadyMsg(); }
    
    static void _call_ready_FileReadyMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_ready_FileReadyMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void run();
     */
    // Entry point registration at startup
    
    static int reg_run_void();
    // Entry point index lookup
    
    inline static int idx_run_void() {
      static int epidx = reg_run_void();
      return epidx;
    }

    
    inline static int idx_run(void (Main::*)() ) {
      return idx_run_void();
    }


    
    static int run() { return idx_run_void(); }
    
    static void _call_run_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_run_void(void* impl_msg, void* impl_obj);
    /* DECLS: void start_read(Ck::IO::SessionReadyMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_start_read_SessionReadyMsg();
    // Entry point index lookup
    
    inline static int idx_start_read_SessionReadyMsg() {
      static int epidx = reg_start_read_SessionReadyMsg();
      return epidx;
    }

    
    inline static int idx_start_read(void (Main::*)(Ck::IO::SessionReadyMsg* impl_msg) ) {
      return idx_start_read_SessionReadyMsg();
    }


    
    static int start_read(Ck::IO::SessionReadyMsg* impl_msg) { return idx_start_read_SessionReadyMsg(); }
    
    static void _call_start_read_SessionReadyMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_start_read_SessionReadyMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void test_read(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_test_read_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_test_read_CkReductionMsg() {
      static int epidx = reg_test_read_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_test_read(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_test_read_CkReductionMsg();
    }


    
    static int test_read(CkReductionMsg* impl_msg) { return idx_test_read_CkReductionMsg(); }
    
    static void _call_test_read_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_test_read_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void closed(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_closed_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_closed_CkReductionMsg() {
      static int epidx = reg_closed_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_closed(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_closed_CkReductionMsg();
    }


    
    static int closed(CkReductionMsg* impl_msg) { return idx_closed_CkReductionMsg(); }
    
    static void _call_closed_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_closed_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void sessionClosed(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_sessionClosed_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_sessionClosed_CkReductionMsg() {
      static int epidx = reg_sessionClosed_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_sessionClosed(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_sessionClosed_CkReductionMsg();
    }


    
    static int sessionClosed(CkReductionMsg* impl_msg) { return idx_sessionClosed_CkReductionMsg(); }
    
    static void _call_sessionClosed_CkReductionMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_sessionClosed_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void iterDone();
     */
    // Entry point registration at startup
    
    static int reg_iterDone_void();
    // Entry point index lookup
    
    inline static int idx_iterDone_void() {
      static int epidx = reg_iterDone_void();
      return epidx;
    }

    
    inline static int idx_iterDone(void (Main::*)() ) {
      return idx_iterDone_void();
    }


    
    static int iterDone() { return idx_iterDone_void(); }
    
    static void _call_iterDone_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_iterDone_void(void* impl_msg, void* impl_obj);
    /* DECLS: void bgDone(double time);
     */
    // Entry point registration at startup
    
    static int reg_bgDone_marshall9();
    // Entry point index lookup
    
    inline static int idx_bgDone_marshall9() {
      static int epidx = reg_bgDone_marshall9();
      return epidx;
    }

    
    inline static int idx_bgDone(void (Main::*)(double time) ) {
      return idx_bgDone_marshall9();
    }


    
    static int bgDone(double time) { return idx_bgDone_marshall9(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_bgDone_marshall9();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_bgDone_marshall9() {
      static int epidx = reg_redn_wrapper_bgDone_marshall9();
      return epidx;
    }
    
    static int redn_wrapper_bgDone(CkReductionMsg* impl_msg) { return idx_redn_wrapper_bgDone_marshall9(); }
    
    static void _call_redn_wrapper_bgDone_marshall9(void* impl_msg, void* impl_obj_void);
    
    static void _call_bgDone_marshall9(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_bgDone_marshall9(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_bgDone_marshall9(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_bgDone_marshall9(PUP::er &p,void *msg);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p);
    }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);

/* DECLS: void ready(Ck::IO::FileReadyMsg* impl_msg);
 */
    
    void ready(Ck::IO::FileReadyMsg* impl_msg);

/* DECLS: void run();
 */
    
    void run(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void start_read(Ck::IO::SessionReadyMsg* impl_msg);
 */
    
    void start_read(Ck::IO::SessionReadyMsg* impl_msg);

/* DECLS: void test_read(CkReductionMsg* impl_msg);
 */
    
    void test_read(CkReductionMsg* impl_msg);

/* DECLS: void closed(CkReductionMsg* impl_msg);
 */
    
    void closed(CkReductionMsg* impl_msg);

/* DECLS: void sessionClosed(CkReductionMsg* impl_msg);
 */
    
    void sessionClosed(CkReductionMsg* impl_msg);

/* DECLS: void iterDone();
 */
    
    void iterDone(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void bgDone(double time);
 */
    
    void bgDone(double time, const CkEntryOptions *impl_e_opts=NULL);

};
#define Main_SDAG_CODE                                                         \
public:                                                                        \
  void run();                                                                  \
  void _sdag_fnc_run();                                                        \
private:                                                                       \
  void run_end();                                                              \
  void _slist_0();                                                             \
  void _slist_0_end();                                                         \
  void _serial_0();                                                            \
  SDAG::Continuation* _when_0();                                               \
  void _when_0_end(Ck::IO::FileReadyMsg* gen0);                                \
  void _serial_1(Ck::IO::FileReadyMsg* gen0);                                  \
  SDAG::Continuation* _when_1();                                               \
  void _when_1_end(Ck::IO::SessionReadyMsg* gen0);                             \
  void _serial_2(Ck::IO::SessionReadyMsg* gen0);                               \
  SDAG::Continuation* _when_2();                                               \
  void _when_2_end(CkReductionMsg* gen0);                                      \
  void _serial_3(CkReductionMsg* gen0);                                        \
  SDAG::Continuation* _when_3();                                               \
  void _when_3_end(CkReductionMsg* gen0);                                      \
  void _serial_4(CkReductionMsg* gen0);                                        \
  SDAG::Continuation* _when_4();                                               \
  void _when_4_end(CkReductionMsg* gen0);                                      \
  void _serial_5(CkReductionMsg* gen0);                                        \
  SDAG::Continuation* _when_5();                                               \
  void _when_5_end(Closure_Main::bgDone_9_closure* gen0);                      \
  void _serial_6(Closure_Main::bgDone_9_closure* gen0);                        \
public:                                                                        \
  void ready(Ck::IO::FileReadyMsg* m_msg);                                     \
  void start_read(Ck::IO::SessionReadyMsg* m_msg);                             \
  void test_read(CkReductionMsg* m_msg);                                       \
  void sessionClosed(CkReductionMsg* m_msg);                                   \
  void closed(CkReductionMsg* m_msg);                                          \
  void bgDone(Closure_Main::bgDone_9_closure* genClosure);                     \
  void bgDone(double time);                                                    \
public:                                                                        \
  SDAG::dep_ptr __dep;                                                         \
  void _sdag_init();                                                           \
  void __sdag_init();                                                          \
public:                                                                        \
  void _sdag_pup(PUP::er &p);                                                  \
  void __sdag_pup(PUP::er &p) { }                                              \
  static void __sdag_register();                                               \
  static int _sdag_idx_Main_serial_0();                                        \
  static int _sdag_reg_Main_serial_0();                                        \
  static int _sdag_idx_Main_serial_1();                                        \
  static int _sdag_reg_Main_serial_1();                                        \
  static int _sdag_idx_Main_serial_2();                                        \
  static int _sdag_reg_Main_serial_2();                                        \
  static int _sdag_idx_Main_serial_3();                                        \
  static int _sdag_reg_Main_serial_3();                                        \
  static int _sdag_idx_Main_serial_4();                                        \
  static int _sdag_reg_Main_serial_4();                                        \
  static int _sdag_idx_Main_serial_5();                                        \
  static int _sdag_reg_Main_serial_5();                                        \
  static int _sdag_idx_Main_serial_6();                                        \
  static int _sdag_reg_Main_serial_6();                                        \

typedef CBaseT1<Chare, CProxy_Main>CBase_Main;

/* DECLS: array Test: ArrayElement{
Test(const Ck::IO::Session &token, const size_t &bytesToRead);
void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
Test(CkMigrateMessage* impl_msg);
};
 */
 class Test;
 class CkIndex_Test;
 class CProxy_Test;
 class CProxyElement_Test;
 class CProxySection_Test;
/* --------------- index object ------------------ */
class CkIndex_Test:public CkIndex_ArrayElement{
  public:
    typedef Test local_t;
    typedef CkIndex_Test index_t;
    typedef CProxy_Test proxy_t;
    typedef CProxyElement_Test element_t;
    typedef CProxySection_Test section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Test(const Ck::IO::Session &token, const size_t &bytesToRead);
     */
    // Entry point registration at startup
    
    static int reg_Test_marshall1();
    // Entry point index lookup
    
    inline static int idx_Test_marshall1() {
      static int epidx = reg_Test_marshall1();
      return epidx;
    }

    
    static int ckNew(const Ck::IO::Session &token, const size_t &bytesToRead) { return idx_Test_marshall1(); }
    
    static void _call_Test_marshall1(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Test_marshall1(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_Test_marshall1(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_Test_marshall1(PUP::er &p,void *msg);
    /* DECLS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_readDone_ReadCompleteMsg();
    // Entry point index lookup
    
    inline static int idx_readDone_ReadCompleteMsg() {
      static int epidx = reg_readDone_ReadCompleteMsg();
      return epidx;
    }

    
    inline static int idx_readDone(void (Test::*)(Ck::IO::ReadCompleteMsg* impl_msg) ) {
      return idx_readDone_ReadCompleteMsg();
    }


    
    static int readDone(Ck::IO::ReadCompleteMsg* impl_msg) { return idx_readDone_ReadCompleteMsg(); }
    
    static void _call_readDone_ReadCompleteMsg(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_readDone_ReadCompleteMsg(void* impl_msg, void* impl_obj);
    /* DECLS: Test(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Test_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Test_CkMigrateMessage() {
      static int epidx = reg_Test_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Test_CkMigrateMessage(); }
    
    static void _call_Test_CkMigrateMessage(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Test_CkMigrateMessage(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Test : public CProxyElement_ArrayElement{
  public:
    typedef Test local_t;
    typedef CkIndex_Test index_t;
    typedef CProxy_Test proxy_t;
    typedef CProxyElement_Test element_t;
    typedef CProxySection_Test section_t;

    using array_index_t = CkArrayIndex1D;

    /* TRAM aggregators */

    CProxyElement_Test(void) {
    }
    CProxyElement_Test(const ArrayElement *e) : CProxyElement_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxyElement_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Test *ckLocal(void) const
    { return (Test *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Test(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Test(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}

    CProxyElement_Test(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {
}
    CProxyElement_Test(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {
}
/* DECLS: Test(const Ck::IO::Session &token, const size_t &bytesToRead);
 */
    
    void insert(const Ck::IO::Session &token, const size_t &bytesToRead, int onPE=-1, const CkEntryOptions *impl_e_opts=NULL);
/* DECLS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void readDone(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: Test(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- collective proxy -------------- */
 class CProxy_Test : public CProxy_ArrayElement{
  public:
    typedef Test local_t;
    typedef CkIndex_Test index_t;
    typedef CProxy_Test proxy_t;
    typedef CProxyElement_Test element_t;
    typedef CProxySection_Test section_t;

    using array_index_t = CkArrayIndex1D;
    CProxy_Test(void) {
    }
    CProxy_Test(const ArrayElement *e) : CProxy_ArrayElement(e){
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxy_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxy_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    // Empty array construction
    static CkArrayID ckNew(CkArrayOptions opts = CkArrayOptions()) { return ckCreateEmptyArray(opts); }
    static void      ckNew(CkCallback cb, CkArrayOptions opts = CkArrayOptions()) { ckCreateEmptyArrayAsync(cb, opts); }

    // Generalized array indexing:
    CProxyElement_Test operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Test(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Test operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Test(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Test operator [] (int idx) const 
        {return CProxyElement_Test(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Test operator () (int idx) const 
        {return CProxyElement_Test(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Test(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Test(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Test(const Ck::IO::Session &token, const size_t &bytesToRead);
 */
    
    static CkArrayID ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, const CkArrayOptions &opts = CkArrayOptions(), const CkEntryOptions *impl_e_opts=NULL);
    static void      ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, const CkArrayOptions &opts, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);
    static CkArrayID ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, const int s1, const CkEntryOptions *impl_e_opts=NULL);
    static void ckNew(const Ck::IO::Session &token, const size_t &bytesToRead, const int s1, CkCallback _ck_array_creation_cb, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void readDone(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: Test(CkMigrateMessage* impl_msg);
 */

};
/* ---------------- section proxy -------------- */
 class CProxySection_Test : public CProxySection_ArrayElement{
  public:
    typedef Test local_t;
    typedef CkIndex_Test index_t;
    typedef CProxy_Test proxy_t;
    typedef CProxyElement_Test element_t;
    typedef CProxySection_Test section_t;

    using array_index_t = CkArrayIndex1D;
    CProxySection_Test(void) {
    }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p);
    }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(CkArrayOptions opts = CkArrayOptions())
    { return CProxySection_ArrayElement::ckCreateEmptyArray(opts); }
    inline static void ckCreateEmptyArrayAsync(CkCallback cb, CkArrayOptions opts = CkArrayOptions())
    { CProxySection_ArrayElement::ckCreateEmptyArrayAsync(cb, opts); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Test operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Test(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Test operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Test(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Test operator [] (int idx) const 
        {return CProxyElement_Test(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Test operator () (int idx) const 
        {return CProxyElement_Test(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex1D> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      return CkSectionID(aid, elems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s, int factor=USE_DEFAULT_BRANCH_FACTOR) {
      std::vector<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.emplace_back(i);
      return CkSectionID(aid, al, factor);
    } 
    CProxySection_Test(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Test(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Test(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems,nElems, factor) {}
    CProxySection_Test(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor=USE_DEFAULT_BRANCH_FACTOR) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    CProxySection_Test(const CkSectionID &sid)  
        :CProxySection_ArrayElement(sid) { ckAutoDelegate(); }
    CProxySection_Test(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Test(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,CK_DELCTOR_ARGS) {}
    CProxySection_Test(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) { ckAutoDelegate(); }
    CProxySection_Test(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems) 
        :CProxySection_ArrayElement(aid,elems) { ckAutoDelegate(); }
    CProxySection_Test(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, int factor) 
        :CProxySection_ArrayElement(n,aid,elems,nElems, factor) { ckAutoDelegate(); }
    CProxySection_Test(const std::vector<CkArrayID> &aid, const std::vector<std::vector<CkArrayIndex> > &elems, int factor) 
        :CProxySection_ArrayElement(aid,elems, factor) { ckAutoDelegate(); }
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems) {
       return CkSectionID(aid, elems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems, int factor) {
      return CkSectionID(aid, elems, nElems, factor);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, const std::vector<CkArrayIndex> &elems, int factor) {
      return CkSectionID(aid, elems, factor);
    } 
    void ckAutoDelegate(int opts=1) {
      if(ckIsDelegated()) return;
      CProxySection_ArrayElement::ckAutoDelegate(opts);
    } 
    void setReductionClient(CkCallback *cb) {
      CProxySection_ArrayElement::setReductionClient(cb);
    } 
    void resetSection() {
      CProxySection_ArrayElement::resetSection();
    } 
    static void contribute(CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, int userData=-1, int fragSize=-1);
    static void contribute(CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    static void contribute(int dataSize,void *data,CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
    template <typename T>
    static void contribute(std::vector<T> &data, CkReduction::reducerType type, CkSectionInfo &sid, const CkCallback &cb, int userData=-1, int fragSize=-1);
/* DECLS: Test(const Ck::IO::Session &token, const size_t &bytesToRead);
 */
    

/* DECLS: void readDone(Ck::IO::ReadCompleteMsg* impl_msg);
 */
    
    void readDone(Ck::IO::ReadCompleteMsg* impl_msg) ;

/* DECLS: Test(CkMigrateMessage* impl_msg);
 */

};
#define Test_SDAG_CODE 
typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Test>CBase_Test;

/* DECLS: group Background: IrrGroup{
Background();
threaded void dummyBackgroundWork();
void setWorkDone();
};
 */
 class Background;
 class CkIndex_Background;
 class CProxy_Background;
 class CProxyElement_Background;
 class CProxySection_Background;
/* --------------- index object ------------------ */
class CkIndex_Background:public CkIndex_IrrGroup{
  public:
    typedef Background local_t;
    typedef CkIndex_Background index_t;
    typedef CProxy_Background proxy_t;
    typedef CProxyElement_Background element_t;
    typedef CProxySection_Background section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Background();
     */
    // Entry point registration at startup
    
    static int reg_Background_void();
    // Entry point index lookup
    
    inline static int idx_Background_void() {
      static int epidx = reg_Background_void();
      return epidx;
    }

    
    static int ckNew() { return idx_Background_void(); }
    
    static void _call_Background_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_Background_void(void* impl_msg, void* impl_obj);
    /* DECLS: threaded void dummyBackgroundWork();
     */
    // Entry point registration at startup
    
    static int reg_dummyBackgroundWork_void();
    // Entry point index lookup
    
    inline static int idx_dummyBackgroundWork_void() {
      static int epidx = reg_dummyBackgroundWork_void();
      return epidx;
    }

    
    inline static int idx_dummyBackgroundWork(void (Background::*)() ) {
      return idx_dummyBackgroundWork_void();
    }


    
    static int dummyBackgroundWork() { return idx_dummyBackgroundWork_void(); }
    
    static void _call_dummyBackgroundWork_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_dummyBackgroundWork_void(void* impl_msg, void* impl_obj);
    
    static void _callthr_dummyBackgroundWork_void(CkThrCallArg *);
    /* DECLS: void setWorkDone();
     */
    // Entry point registration at startup
    
    static int reg_setWorkDone_void();
    // Entry point index lookup
    
    inline static int idx_setWorkDone_void() {
      static int epidx = reg_setWorkDone_void();
      return epidx;
    }

    
    inline static int idx_setWorkDone(void (Background::*)() ) {
      return idx_setWorkDone_void();
    }


    
    static int setWorkDone() { return idx_setWorkDone_void(); }
    
    static void _call_setWorkDone_void(void* impl_msg, void* impl_obj);
    
    static void _call_sdag_setWorkDone_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
class CProxyElement_Background: public CProxyElement_IrrGroup{
  public:
    typedef Background local_t;
    typedef CkIndex_Background index_t;
    typedef CProxy_Background proxy_t;
    typedef CProxyElement_Background element_t;
    typedef CProxySection_Background section_t;


    /* TRAM aggregators */

    CProxyElement_Background(void) {
    }
    CProxyElement_Background(const IrrGroup *g) : CProxyElement_IrrGroup(g){
    }
    CProxyElement_Background(CkGroupID _gid,int _onPE,CK_DELCTOR_PARAM) : CProxyElement_IrrGroup(_gid,_onPE,CK_DELCTOR_ARGS){
    }
    CProxyElement_Background(CkGroupID _gid,int _onPE) : CProxyElement_IrrGroup(_gid,_onPE){
    }

    int ckIsDelegated(void) const
    { return CProxyElement_IrrGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_IrrGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_IrrGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_IrrGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxyElement_IrrGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxyElement_IrrGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxyElement_IrrGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_IrrGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_IrrGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_IrrGroup::ckSetReductionClient(cb); }
int ckGetGroupPe(void) const
{return CProxyElement_IrrGroup::ckGetGroupPe();}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_IrrGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_IrrGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_IrrGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxyElement_IrrGroup::ckSetGroupID(g);
    }
    Background* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static Background* ckLocalBranch(CkGroupID gID) {
      return (Background*)CkLocalBranch(gID);
    }
/* DECLS: Background();
 */
    

/* DECLS: threaded void dummyBackgroundWork();
 */
    
    void dummyBackgroundWork(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void setWorkDone();
 */
    
    void setWorkDone(const CkEntryOptions *impl_e_opts=NULL);

};
/* ---------------- collective proxy -------------- */
class CProxy_Background: public CProxy_IrrGroup{
  public:
    typedef Background local_t;
    typedef CkIndex_Background index_t;
    typedef CProxy_Background proxy_t;
    typedef CProxyElement_Background element_t;
    typedef CProxySection_Background section_t;

    CProxy_Background(void) {
    }
    CProxy_Background(const IrrGroup *g) : CProxy_IrrGroup(g){
    }
    CProxy_Background(CkGroupID _gid,CK_DELCTOR_PARAM) : CProxy_IrrGroup(_gid,CK_DELCTOR_ARGS){  }
    CProxy_Background(CkGroupID _gid) : CProxy_IrrGroup(_gid){  }
    CProxyElement_Background operator[](int onPE) const
      {return CProxyElement_Background(ckGetGroupID(),onPE,CK_DELCTOR_CALL);}

    int ckIsDelegated(void) const
    { return CProxy_IrrGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_IrrGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_IrrGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_IrrGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxy_IrrGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxy_IrrGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxy_IrrGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_IrrGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_IrrGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_IrrGroup::ckSetReductionClient(cb); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_IrrGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_IrrGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_IrrGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxy_IrrGroup::ckSetGroupID(g);
    }
    Background* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static Background* ckLocalBranch(CkGroupID gID) {
      return (Background*)CkLocalBranch(gID);
    }
/* DECLS: Background();
 */
    
    static CkGroupID ckNew(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: threaded void dummyBackgroundWork();
 */
    
    void dummyBackgroundWork(const CkEntryOptions *impl_e_opts=NULL);
    
    void dummyBackgroundWork(int npes, int *pes, const CkEntryOptions *impl_e_opts=NULL);
    
    void dummyBackgroundWork(CmiGroup &grp, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void setWorkDone();
 */
    
    void setWorkDone(const CkEntryOptions *impl_e_opts=NULL);
    
    void setWorkDone(int npes, int *pes, const CkEntryOptions *impl_e_opts=NULL);
    
    void setWorkDone(CmiGroup &grp, const CkEntryOptions *impl_e_opts=NULL);

};
/* ---------------- section proxy -------------- */
class CProxySection_Background: public CProxySection_IrrGroup{
  public:
    typedef Background local_t;
    typedef CkIndex_Background index_t;
    typedef CProxy_Background proxy_t;
    typedef CProxyElement_Background element_t;
    typedef CProxySection_Background section_t;

    CProxySection_Background(void) {
    }
    CProxySection_Background(const IrrGroup *g) : CProxySection_IrrGroup(g){
    }
    CProxySection_Background(const CkGroupID &_gid,const int *_pelist,int _npes, CK_DELCTOR_PARAM) : CProxySection_IrrGroup(_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }
    CProxySection_Background(const CkGroupID &_gid,const int *_pelist,int _npes, int factor = USE_DEFAULT_BRANCH_FACTOR) : CProxySection_IrrGroup(_gid,_pelist,_npes,factor){  }
    CProxySection_Background(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes, int factor = USE_DEFAULT_BRANCH_FACTOR) : CProxySection_IrrGroup(n,_gid,_pelist,_npes,factor){  }
    CProxySection_Background(int n,const CkGroupID *_gid, int const * const *_pelist,const int *_npes, CK_DELCTOR_PARAM) : CProxySection_IrrGroup(n,_gid,_pelist,_npes,CK_DELCTOR_ARGS){  }

    int ckIsDelegated(void) const
    { return CProxySection_IrrGroup::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_IrrGroup::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_IrrGroup::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_IrrGroup::ckDelegatedIdx(); }
inline void ckCheck(void) const {CProxySection_IrrGroup::ckCheck();}
CkChareID ckGetChareID(void) const
   {return CProxySection_IrrGroup::ckGetChareID();}
CkGroupID ckGetGroupID(void) const
   {return CProxySection_IrrGroup::ckGetGroupID();}
operator CkGroupID () const { return ckGetGroupID(); }

    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_IrrGroup::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_IrrGroup::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_IrrGroup::ckSetReductionClient(cb); }
inline int ckGetNumSections() const
{ return CProxySection_IrrGroup::ckGetNumSections(); }
inline CkSectionInfo &ckGetSectionInfo()
{ return CProxySection_IrrGroup::ckGetSectionInfo(); }
inline CkSectionID *ckGetSectionIDs()
{ return CProxySection_IrrGroup::ckGetSectionIDs(); }
inline CkSectionID &ckGetSectionID()
{ return CProxySection_IrrGroup::ckGetSectionID(); }
inline CkSectionID &ckGetSectionID(int i)
{ return CProxySection_IrrGroup::ckGetSectionID(i); }
inline CkGroupID ckGetGroupIDn(int i) const
{ return CProxySection_IrrGroup::ckGetGroupIDn(i); }
inline const int *ckGetElements() const
{ return CProxySection_IrrGroup::ckGetElements(); }
inline const int *ckGetElements(int i) const
{ return CProxySection_IrrGroup::ckGetElements(i); }
inline int ckGetNumElements() const
{ return CProxySection_IrrGroup::ckGetNumElements(); } 
inline int ckGetNumElements(int i) const
{ return CProxySection_IrrGroup::ckGetNumElements(i); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_IrrGroup::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_IrrGroup::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_IrrGroup::pup(p);
    }
    void ckSetGroupID(CkGroupID g) {
      CProxySection_IrrGroup::ckSetGroupID(g);
    }
    Background* ckLocalBranch(void) const {
      return ckLocalBranch(ckGetGroupID());
    }
    static Background* ckLocalBranch(CkGroupID gID) {
      return (Background*)CkLocalBranch(gID);
    }
/* DECLS: Background();
 */
    

/* DECLS: threaded void dummyBackgroundWork();
 */
    
    void dummyBackgroundWork(const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void setWorkDone();
 */
    
    void setWorkDone(const CkEntryOptions *impl_e_opts=NULL);

};
#define Background_SDAG_CODE 
typedef CBaseT1<Group, CProxy_Background>CBase_Background;


/* ---------------- method closures -------------- */
class Closure_Main {
  public:



    struct run_3_closure;






    struct iterDone_8_closure;


    struct bgDone_9_closure;

};

/* ---------------- method closures -------------- */
class Closure_Test {
  public:



};

/* ---------------- method closures -------------- */
class Closure_Background {
  public:


    struct dummyBackgroundWork_2_closure;


    struct setWorkDone_3_closure;

};

extern void _registeriotest(void);
extern "C" void CkRegisterMainModule(void);
#endif
