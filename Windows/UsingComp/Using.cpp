/////////////////////////////////////////////////////////////////////////////////////////////
// Helper.cpp - Text Search Component Implementation                                       //
// Platform:    Microsoft Windows 10 Home DESKTOP-77C646O 10.0.17134 Multiprocessor 64-bit //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu> , Jim Fawcett                              //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Using.h"
#include "../HelperComp/HelperComp_i.h"
#include <string>
#include <comdef.h>
#include <codecvt>
#include<locale>
#include <iostream>
#include <vector>
#include<fstream>
#include<regex>
#include<sstream>

using namespace std;
vector<string> split(string str, string sep)
{
	char* cstr = const_cast<char*> (str.c_str());
	char* current;
	vector<string> arr;
	current = strtok(cstr, sep.c_str());
	while (current != NULL) {
		arr.push_back(current);
		current = strtok(NULL, sep.c_str());
	}
	return arr;
}
string bstr2str(BSTR bstr) {
	std::wstring ws(bstr, SysStringLen(bstr));
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;
	return converter.to_bytes(ws);
}
STDMETHODIMP CUsing::sendRegex(BSTR regex)
{
	this->regex_ = regex;
	return S_OK;
}
/*----< receive interface pointer to helper component >--------------*/

STDMETHODIMP CUsing::sendHelperIF(IUnknown* pHelperIF)
{
  pHelperUnk_ = pHelperIF;
  return S_OK;
}

STDMETHODIMP CUsing::run()
{
	string s_files = bstr2str(this->files_);
	vector<string> s_filesList = split(s_files, ",");

	ifstream ifh;
	string line;
	smatch m;
	regex re(bstr2str(this->regex_));
	for (string file : s_filesList) {
		ifh.open(file);
		if (!ifh)
			continue;
		string pResult = "\n    " + file;
		stringstream ss("");
		int lineCount = 0;
		while (getline(ifh, line)) {
			lineCount++;
			if (regex_search(line, m, re))
				pResult += "\n        Line " + to_string(lineCount) + ": " + line;
		}
		ifh.close();

		this->results_.Append(pResult.c_str());
	}
	return S_OK;
}

/*----< return demo result to client --------------------------------*/
/*
*  Uses helper's get result to compute returned result
*/
STDMETHODIMP CUsing::getResult(BSTR* pResult)
{
  // CComQIPtr<IHelper> is smart enough that the construction, below
  // uses QueryInterface, internally, to return a pointer to IHelper.

  CComQIPtr<IHelper> pHelper = pHelperUnk_;  // note: pHelper is a smart pointer object created with this declaration
  if (!pHelper)
    return E_NOINTERFACE;

  BSTR helperResult;
  HRESULT hr = pHelper->getResult(&helperResult);
  
  this->files_ = helperResult;
  run();
  if (!SUCCEEDED(hr))
    return E_FAIL;

  CComBSTR result("Here's the result along with ");
  result += helperResult;
  result = this->results_;

  *pResult = result.Detach();
  return S_OK;
}
