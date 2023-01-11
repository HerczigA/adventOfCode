#pragma once 
#include "utils.h" 

const uint32_t minSize=100000;
const uint32_t totalSize=70000000;
const uint32_t updateSize=30000000;
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
        void collectDirectoriesForGetFreeSpace();
        void collectTotalSizeUnder100000();
        void stepBack();
                
        string mCdCmd="$";
        uint64_t mTotalSize;
        map<string, uint64_t> mOs;
        set<uint64_t> mAvailableDirs;
        string mPath="/home";
        
        
};
        