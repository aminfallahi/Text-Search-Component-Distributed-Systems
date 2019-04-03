#pragma once
/////////////////////////////////////////////////////////////////////////////////////////////
// IFileMgr.h - Interface for File Manager Component                                       //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////


#include <vector>

using namespace std;

class IFileMgr {
public:
    virtual ~IFileMgr(){};
    virtual void setPatterns(vector<string> patterns) = 0;
    virtual void setPath(string path) = 0;
    virtual string getPath() = 0;
    virtual vector<string> getFiles(string path="") = 0;
    virtual int checkError(){};
    virtual void getResults(vector<string> &res) = 0;
};

extern "C" {                  // unmangled global factory
  IFileMgr* globalCreateFileMgr();
}