/////////////////////////////////////////////////////////////////////////////////////////////
// Helper.cpp - File Manager Component Implementation                                      //
// Platform:    Microsoft Windows 10 Home DESKTOP-77C646O 10.0.17134 Multiprocessor 64-bit //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu> , Jim Fawcett                              //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Helper.h"
#include <string>
#include <comdef.h>
#include <codecvt>
#include<locale>
#include <iostream>
#include <vector>
#include "FileSystem.h"

using namespace std;
using namespace FileSystem;

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

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	return converter.to_bytes(ws);
}

//----< receives a path from client >----------------------------------
/*
* - used only as part of result sent to client from Using component
*/
STDMETHODIMP CHelper::SendPath(BSTR path)
{
  path_.Append(path);
  return S_OK;
}

STDMETHODIMP CHelper::SendPath2(BSTR path, BSTR patterns)
{
	this->path_.Append(path);
	this->patterns_.Append(patterns);
	return S_OK;
}

STDMETHODIMP CHelper::run(BSTR path)
{
	vector<string> s_paths;
	string s_path = bstr2str(path);
	if (s_path == "")
		path = this->path_;
	string s_patterns;
	s_patterns = bstr2str(this->patterns_);
	vector<string> s_patternsList;
	s_patternsList = split(s_patterns, ",");

	
	// Search for files in the current directory
	for (string s_pattern : s_patternsList) {
		vector<string> files = Directory::getFiles(s_path, s_pattern);
		for (string file : files) {
			string ppath = s_path + "/" + file+",";
			this->files_.Append(ppath.c_str());
		}
	}
	
	// Get all the directories under current path and recursively call run for them
	for (string dir : Directory::getDirectories(s_path)) {
		if (dir == "." || dir == "..")
			continue;
		string ppath = s_path + "/" + dir;
		CComBSTR bstr_ppath;
		bstr_ppath.Append(ppath.c_str());
		run(bstr_ppath);
	}

	return S_OK;
}
//----< provides a string for Using to send back to client >-----------

STDMETHODIMP CHelper::getResult(BSTR* pResult)
{
  run(this->path_);
  CComBSTR result(this->files_);
  *pResult = result.Detach();
  return S_OK;
}
