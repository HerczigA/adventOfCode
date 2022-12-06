#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <array>
#include <map>
#include <set>

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
        string& getFileName(int index);
        virtual void getInput(string& filePath) = 0;
        virtual void doWork() = 0;
        virtual void printResults() = 0;
        virtual ~Days(){};
    protected:
        int openInput(string &filePath, ifstream& file);
    private:
        
        vector<string> mAdventInputs{
                    "../adventUtil/inputFirstDay.txt",
                    "../adventUtil/inputSecondDay.txt",
                    "../adventUtil/inputThirdDay.txt",
                    "../adventUtil/inputFourthDay.txt",
                    #if USE_PROBE_FILE
                    "../adventUtil/probe.txt"
                    #endif
        } ;      
};

