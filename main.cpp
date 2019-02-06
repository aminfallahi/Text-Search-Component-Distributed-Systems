/* 
 * File:   main.cpp
 * Author: amin
 *
 * Created on February 5, 2019, 7:46 PM
 */

#include <cstdlib>
#include<string>
#include<iostream>
#include "textSearch.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    textSearch a("test.txt","(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    string x;
    x=a.run();
    cout<<x;
    return 0;
}

