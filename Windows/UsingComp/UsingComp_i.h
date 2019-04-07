

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for UsingComp.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __UsingComp_i_h__
#define __UsingComp_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUsing_FWD_DEFINED__
#define __IUsing_FWD_DEFINED__
typedef interface IUsing IUsing;

#endif 	/* __IUsing_FWD_DEFINED__ */


#ifndef __Using_FWD_DEFINED__
#define __Using_FWD_DEFINED__

#ifdef __cplusplus
typedef class Using Using;
#else
typedef struct Using Using;
#endif /* __cplusplus */

#endif 	/* __Using_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IUsing_INTERFACE_DEFINED__
#define __IUsing_INTERFACE_DEFINED__

/* interface IUsing */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUsing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e69d2713-6f95-4018-be91-00ffb29c26b0")
    IUsing : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE sendHelperIF( 
            /* [in] */ IUnknown *pHelperIF) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE getResult( 
            /* [retval][out] */ BSTR *pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE sendRegex( 
            /* [in] */ BSTR regex) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE run( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IUsingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUsing * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUsing * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUsing * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUsing * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUsing * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUsing * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUsing * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *sendHelperIF )( 
            IUsing * This,
            /* [in] */ IUnknown *pHelperIF);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *getResult )( 
            IUsing * This,
            /* [retval][out] */ BSTR *pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *sendRegex )( 
            IUsing * This,
            /* [in] */ BSTR regex);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *run )( 
            IUsing * This);
        
        END_INTERFACE
    } IUsingVtbl;

    interface IUsing
    {
        CONST_VTBL struct IUsingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUsing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUsing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUsing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUsing_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUsing_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUsing_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUsing_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUsing_sendHelperIF(This,pHelperIF)	\
    ( (This)->lpVtbl -> sendHelperIF(This,pHelperIF) ) 

#define IUsing_getResult(This,pResult)	\
    ( (This)->lpVtbl -> getResult(This,pResult) ) 

#define IUsing_sendRegex(This,regex)	\
    ( (This)->lpVtbl -> sendRegex(This,regex) ) 

#define IUsing_run(This)	\
    ( (This)->lpVtbl -> run(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUsing_INTERFACE_DEFINED__ */



#ifndef __UsingCompLib_LIBRARY_DEFINED__
#define __UsingCompLib_LIBRARY_DEFINED__

/* library UsingCompLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_UsingCompLib;

EXTERN_C const CLSID CLSID_Using;

#ifdef __cplusplus

class DECLSPEC_UUID("ec0489bd-9751-4209-9c45-1e9b2587ce13")
Using;
#endif
#endif /* __UsingCompLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


