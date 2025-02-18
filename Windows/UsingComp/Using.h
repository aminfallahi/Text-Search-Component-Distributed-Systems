// Using.h : Declaration of the CUsing

#pragma once
#include "resource.h"       // main symbols



#include "UsingComp_i.h"
#include "../HelperComp/HelperComp_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CUsing

class ATL_NO_VTABLE CUsing :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUsing, &CLSID_Using>,
	public IDispatchImpl<IUsing, &IID_IUsing, &LIBID_UsingCompLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CUsing()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CUsing)
	COM_INTERFACE_ENTRY(IUsing)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
  STDMETHOD(sendHelperIF)(IUnknown* pHelperIF);
  STDMETHOD(getResult)(BSTR* pResult);
  STDMETHOD(sendRegex)(BSTR regex);
  STDMETHOD(run)();

private:
  IUnknown * pHelperUnk_;
  CComBSTR regex_;
  CComBSTR files_;
  CComBSTR results_;
};

OBJECT_ENTRY_AUTO(__uuidof(Using), CUsing)
