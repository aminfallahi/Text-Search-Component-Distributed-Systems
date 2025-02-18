// Helper.h : Declaration of the CHelper

#pragma once
#include "resource.h"       // main symbols



#include "HelperComp_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CHelper

class ATL_NO_VTABLE CHelper :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelper, &CLSID_Helper>,
	public IDispatchImpl<IHelper, &IID_IHelper, &LIBID_HelperCompLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHelper()
	{
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CHelper)
	COM_INTERFACE_ENTRY(IHelper)
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
	STDMETHOD(SendPath)(BSTR path);
	STDMETHOD(SendPath2)(BSTR path, BSTR patterns);
	STDMETHOD(run)(BSTR path);
	STDMETHOD(getResult)(BSTR* pResult);
private:
  CComBSTR path_;
  CComBSTR patterns_;
  CComBSTR files_;
};

OBJECT_ENTRY_AUTO(__uuidof(Helper), CHelper)
