/////////////////////////////////////////////////////////////////////////////////////////////
// TextSearch.cpp - Test Search Component Header                                           //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "ITextSearch.h"
using namespace std;

class TextSearch : public ITextSearch {
public:
    TextSearch();
    virtual ~TextSearch();
    virtual vector<string> getResult(string regEx) override;
    virtual void setFileMgrIF(IFileMgr *fileMgr) override;
private:
    IFileMgr* fileMgr;
};
