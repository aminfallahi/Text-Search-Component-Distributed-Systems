/////////////////////////////////////////////////////////////////////////////////////////////
// Client.cpp - Client which uses File Manager and Text Search Components                  //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////

#include <dlfcn.h>  // get access to dlopen and dlsym
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>
#include "../FileMgrComp/IFileMgr.h"
#include "../TextSearchComp/ITextSearch.h"

using namespace std;

vector<string> split(string str, string sep);

int main(int argc, char** argv)
{
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
	cout << "\n RegEx: " << inputRegEx<<"\n\n";

	void* fmHandle = dlopen("./libFileMgr.so", RTLD_LAZY);
	if (!fmHandle) {
		cout << "\n  failed to load libFileMgr.so\n\n";
		return 1;
	}

	void* tsHandle = dlopen("./libTextSearch.so", RTLD_LAZY);
	if (!tsHandle) {
		cout << "\n  failed to load libTextSearch.so\n\n";
		return 1;
	}

	typedef IFileMgr * (*GCreateFileMgr)();
	typedef ITextSearch * (*GCreateTextSearch)();
	GCreateFileMgr gCreateFileMgr = (GCreateFileMgr) dlsym(fmHandle, "globalCreateFileMgr");
	GCreateTextSearch gCreateTextSearch = (GCreateTextSearch) dlsym(tsHandle, "globalCreateTextSearch");

	if (!gCreateFileMgr) {
		cout << "\n  failed to acquire create function for File Manager component\n\n";
		return 1;
	}
	if (!gCreateTextSearch) {
		cout << "\n  failed to acquire create function for Text Search component\n\n";
		return 1;
	}

	IFileMgr *pFileMgr = gCreateFileMgr();

	vector<string> patterns = split(inputPatterns, ",");
	pFileMgr->setPatterns(patterns);

	pFileMgr->setPath(inputPath);

	//cout << "\n  Selected directories:";
	vector<string> paths = pFileMgr->getFiles();

	cout << "\n\n  Selected files: ";
	for (string path : paths)
		cout << "\n    " << path;


	ITextSearch *pTextSearch = gCreateTextSearch();
	string regEx = inputRegEx;
	vector<string> results = pTextSearch->GetResult(regEx, pFileMgr);
	cout << "\n\n  Results:";
	for (string result : results) {
		cout << result << "\n";
	}
	dlclose(fmHandle);
	dlclose(tsHandle);

	cout << "\n\n";

	return 0;
}

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