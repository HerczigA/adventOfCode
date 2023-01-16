#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <array>
#include <map>
#include <set>
#include <bits/stdc++.h>
#include <sstream>
#include <algorithm>
#include <list>

using namespace std;

#ifndef DEBUG_ADVENT
    #define DEBUG_ADVENT 0
#endif

#ifndef USE_PROBE_FILE
    #define USE_PROBE_FILE 0
#endif


class Days{
    public:
        enum DAYS{
            FIRST_DAY,
            SECONDY_DAY,
            THIRD_DAY,
            FOURTH_DAY
        };

        virtual void getInput(string& filePath) = 0;
        virtual void doWork() = 0;
        virtual ~Days(){};
    protected:
        virtual void printResults() = 0;    
        int openInput(string &filePath, ifstream& file);
    private:
        
          
};

