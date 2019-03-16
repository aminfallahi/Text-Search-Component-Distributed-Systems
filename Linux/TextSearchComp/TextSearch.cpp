/////////////////////////////////////////////////////////////////////////////////////////////
// TextSearch.cpp - Test Search Component Implementation                                   //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "ITextSearch.h"
#include "TextSearch.h"

using namespace std;



TextSearch::TextSearch()
{
}

TextSearch::~TextSearch()
{
}

void TextSearch::setFileMgrIF(IFileMgr *fileMgr){
	this->fileMgr=fileMgr;
	
}

vector<string> TextSearch::getResult(string regEx)
{
	vector<string> files = this->fileMgr->getFiles();
	vector<string> result;
	if (this->fileMgr->checkError()){
		cout<<"\n    Error on getting files.";
		return result;
	}
	ifstream ifh;
	string line;
	smatch m;
	regex re(regEx);
	for (string file : files) {
		ifh.open(file);
		if (!ifh)
			continue;
		string pResult = "\n    " + file;
		stringstream ss("");
		int lineCount = 0;
		while (getline(ifh, line)) {
			lineCount++;
			if (regex_search(line, m, re))
				pResult+="\n        Line " + to_string(lineCount) + ": " + line;
		}
		ifh.close();

		result.push_back(pResult);
	}
	return result;
}

ITextSearch* globalCreateTextSearch()
{
	return new TextSearch();
}