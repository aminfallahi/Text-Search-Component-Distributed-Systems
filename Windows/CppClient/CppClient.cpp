///////////////////////////////////////////////////////////////////////
// Client.cpp - creates Helper and Using, hooks together, and uses   //
//                                                                   //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2018            //
///////////////////////////////////////////////////////////////////////

#include <atlbase.h>
#include <iostream>
#include <string>
#include "../HelperComp/HelperComp_i.h"
#include "../UsingComp/UsingComp_i.h"

int main()
{
  std::cout << "\n  CSE775 Project #1 Helper client";
  std::cout << "\n =================================";
  CoInitialize(NULL);
  {
    // create a Helper instance

    CComQIPtr<IHelper> pHelper;
    pHelper.CoCreateInstance(CLSID_Helper);
    if (pHelper)
    {
      // send path string to helper

      CComBSTR path("../testfiles");
	  CComBSTR patterns("*.txt,*.cpp");
      pHelper->SendPath2(path,patterns);
    }
    // create a Using instance

    CComQIPtr<IUsing> pUsing;
    pUsing.CoCreateInstance(CLSID_Using);
    if (pUsing)
    {
      // send Using an IUnknow pointer to Helper

      pUsing->sendHelperIF(pHelper);
	  CComBSTR regex("^([a-zA-Z0-9]+)@([a-zA-Z0-9]+)\.([a-zA-Z]{2,5})$");
	  pUsing->sendRegex(regex);

      // get result from Using

      BSTR result;
      pUsing->getResult(&result);
      std::wcout << "\n  " << result;
    }
    std::wcout << "\n\n";
  }
  CoUninitialize();
  return 0;
}

