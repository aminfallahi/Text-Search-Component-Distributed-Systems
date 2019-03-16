/////////////////////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp - File Manager Component Header                                             //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "IFileMgr.h"
#include "FileSystem.h"
using namespace FileSystem;
using namespace std;

class FileMgr : public IFileMgr {
public:
	FileMgr();
	virtual ~FileMgr();
	virtual void setPatterns(vector<string> patterns) override;
	virtual void setPath(string path) override;
	virtual string getPath() override;
	virtual vector<string> getFiles(string path = "") override;
        virtual int checkError() override;
private:
	vector<string> patterns;
	string path;
        int error=0;
};
