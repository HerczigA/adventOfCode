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




class Days{
    public:
        enum DAYS{
            FIRST_DAY,
            SECONDY_DAY,
            THIRD_DAY
        };
        string& getFileName(int index);
        virtual void getInput(string& filePath, vector<int>& data);
        virtual void getInput(string& filePath, vector<string>& data);
        virtual void getInput(string& filePath, multimap<string, string>& data);
        virtual void doWork(void* param) = 0;
        virtual void printResults() = 0;
        virtual ~Days(){};
    private:
        int openInput(string &filePath, ifstream& myfile);
        vector<string> mAdventInputs{
                    "../adventUtil/inputFirstDay.txt",
                    "../adventUtil/inputSecondDay.txt",
                    "../adventUtil/inputThirdDay.txt",
                    "../adventUtil/proba.txt"
        } ;

        
};

