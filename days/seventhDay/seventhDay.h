#pragma once 
#include "utils.h" 

const uint32_t minSize=100000;
const uint8_t DIR_LENGTH_CUTOFF=5;

class SeventhDay : public Days 
{
    public:
        SeventhDay();
        void doWork() override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
        
        void createOs(string & line, ifstream & inputfile);
        void parseDir(string& line);
        void countDirSize(string & line);
        void stepBack();
                
        string mCdCmd="$";
        uint64_t mTotalSize;
        map<string, uint64_t> mOs;
        string mPath="/home";
        
        
};
        