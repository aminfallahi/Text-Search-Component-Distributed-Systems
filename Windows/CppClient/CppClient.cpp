/////////////////////////////////////////////////////////////////////////////////////////////
// CppClient.cpp - Client which uses File Manager and Text Search Components               //
// Platform:    Microsoft Windows 10 Home DESKTOP-77C646O 10.0.17134 Multiprocessor 64-bit //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu> , Jim Fawcett                              //
/////////////////////////////////////////////////////////////////////////////////////////////

#include <atlbase.h>
#include <iostream>
#include <string>
#include "../HelperComp/HelperComp_i.h"
#include "../UsingComp/UsingComp_i.h"
using namespace std;
int main(int argc, char** argv)
{

  std::cout << "\n  CSE775 Project #1 Helper client";
  std::cout << "\n =================================";
  string inputPath = argv[1] == NULL ? "." : argv[1];
  string inputPatterns = argv[2] == NULL ? "*" : argv[2];
  string inputRegEx;
  if (argv[3] == NULL)
	  inputRegEx = "*";
  else {
	  for (int i = 3; i < argc; i++)
		  inputRegEx += argv[i];
  }
  cout << "\n  Text Search Demo";
  cout << "\n ================================\n";
  cout << "\n Path: " << inputPath;
  cout << "\n Patterns: " << inputPatterns;
  cout << "\n RegEx: " << inputRegEx << "\n\n";
  CoInitialize(NULL);
  {
    // create a Helper instance

    CComQIPtr<IHelper> pHelper;
    pHelper.CoCreateInstance(CLSID_Helper);
    if (pHelper)
    {
      // send path string to helper

      CComBSTR path(inputPath.c_str());
	  CComBSTR patterns(inputPatterns.c_str());
      pHelper->SendPath2(path,patterns);
    }
    // create a Using instance
    CComQIPtr<IUsing> pUsing;
    pUsing.CoCreateInstance(CLSID_Using);
    if (pUsing)
    {
      // send Using an IUnknow pointer to Helper

      pUsing->sendHelperIF(pHelper);
	  CComBSTR regex(inputRegEx.c_str());
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

