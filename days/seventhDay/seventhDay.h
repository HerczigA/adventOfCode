#pragma once 
#include "utils.h" 

class SeventhDay : public Days 
{
    public:
        SeventhDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;        
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
        