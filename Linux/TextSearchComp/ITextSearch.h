#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////
// ITextSearch.h - Interface for Test Search Component                                     //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include "../FileMgrComp/IFileMgr.h"

using namespace std;

class ITextSearch {
public:
    virtual ~ITextSearch(){};
    virtual vector<string> GetResult(string regEx, IFileMgr* fileMgr) = 0;
};

extern "C" {                  // unmangled global factory
  ITextSearch* globalCreateTextSearch();
}