// dllmain.h : Declaration of module class.

class CHelperCompModule : public ATL::CAtlDllModuleT< CHelperCompModule >
{
public :
	DECLARE_LIBID(LIBID_HelperCompLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_HELPERCOMP, "{71e46a0a-89e2-4e1b-b605-fb21a1862e08}")
};

extern class CHelperCompModule _AtlModule;
