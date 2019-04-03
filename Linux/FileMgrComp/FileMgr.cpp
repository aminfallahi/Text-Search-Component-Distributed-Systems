/////////////////////////////////////////////////////////////////////////////////////////////
// FileMgr.cpp - File Manager Component Implementation                                     //
// Linux ver 1.0                                                                           //
// Language:    gcc/g++ v8.3.0                                                             //
// Platform:    Linux 4.19.0-2-amd64 #1 SMP Debian 4.19.16-1 (2019-01-17) x86_64 GNU/Linux //
// Application: CSE-775 Distributed Objects - Project #1                                   //
// Author:      Amin Fallahi <afallahi@syr.edu>                                            //
/////////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
#include "IFileMgr.h"
#include "FileSystem.h"
#include "FileMgr.h"
using namespace FileSystem;
using namespace std;

FileMgr::FileMgr()
{
}

FileMgr::~FileMgr()
{
}

void FileMgr::setPath(string path)
{
	this->path = path;
}

string FileMgr::getPath()
{
	return path;
}

void FileMgr::setPatterns(vector<string> patterns)
{
	this->patterns = patterns;
}

// Search for files and directories recursively, if path is not passed, uses path from object to start

vector<string> FileMgr::getFiles(string path)
{
	vector<string> paths;
	if (path == "")
		path = this->path;

	// Search for files in the current directory
	for (string pattern : patterns) {
		vector<string> files = Directory::getFiles(path, pattern);
		for (string file : files) {
			paths.push_back(path + "/" + file);
		}
	}

	// Get all the directories under current path and recursively call getFiles for them
	for (string dir : Directory::getDirectories(path)) {
		vector<string> subPaths = getFiles(path + "/" + dir);
		paths.insert(paths.end(), subPaths.begin(), subPaths.end());
	}
	this->results = paths;
	return paths;
}

int FileMgr::checkError()
{
	return this->error;
}

void FileMgr::getResults(vector<string> &res)
{
	res=this->results;
}

IFileMgr* globalCreateFileMgr()
{
	return new FileMgr();
}