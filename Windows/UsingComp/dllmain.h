// dllmain.h : Declaration of module class.

class CUsingCompModule : public ATL::CAtlDllModuleT< CUsingCompModule >
{
public :
	DECLARE_LIBID(LIBID_UsingCompLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_USINGCOMP, "{6c6f396a-8e16-485d-8fac-ca5676d27cfe}")
};

extern class CUsingCompModule _AtlModule;
