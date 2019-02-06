/* 
 * File:   textSearch.cpp
 * Author: amin
 * 
 * Created on February 5, 2019, 7:46 PM
 */

#include "textSearch.h"
#include<string>
#include<fstream>
#include<regex>

using namespace std;

textSearch::textSearch() {
}

textSearch::textSearch(const textSearch& orig) {
}

textSearch::~textSearch() {
}

textSearch::textSearch(string filePath, string re){
    this->filePath=filePath;
    this->re=re;
}

string textSearch::run(){
    std::ifstream fileHandle;
    fileHandle.open(filePath);
    std::string line;
    string out;
    while (std::getline(fileHandle, line)){
        std::regex e(re);
        bool match= regex_search(line, e);
        if (match){
            out=out+line+"\n";
        }
    }
    return out;
}