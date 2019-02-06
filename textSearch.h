/* 
 * File:   textSearch.h
 * Author: amin
 *
 * Created on February 5, 2019, 7:46 PM
 */

#ifndef TEXTSEARCH_H
#define	TEXTSEARCH_H

#include<string>

using namespace std;
class textSearch {
public:
    textSearch();
    textSearch(const textSearch& orig);
    textSearch(string, string);
    string run();
    virtual ~textSearch();
private:
    string re;
    string filePath;

};

#endif	/* TEXTSEARCH_H */

