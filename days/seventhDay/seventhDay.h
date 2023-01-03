#pragma once 
#include "utils.h" 
// #include <list>

const uint32_t minSize=100000;
const uint8_t DIR_LENGTH_CUTOFF=4;



class SeventhDay : public Days 
{
    enum POSITION_LEVEL
    {
        ROOT,
        DIR,
        SUBDIR,
        SOMEWHERE_IN_THE_DEEP
    };

    public:
        SeventhDay();
        void doWork() override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
        struct DirectoryScope
        {
            DirectoryScope();
            DirectoryScope(string fileName)
            : actualSubDirIndex(0)
            , fileSize(0)
            , name(fileName)
            , head(nullptr)
            , subDirs(nullptr)
            {

            };
            int actualSubDirIndex;
            set<string> dirNames;
            uint32_t fileSize;
            string name;
            DirectoryScope* head;
            DirectoryScope** subDirs;
        };

        uint32_t sumOfDirectoriesAtMost100000();
        bool checkSize();
        int stepInto(string& dir);
        void parseDir(string& line);
        void parseFile(string & line);
        void walk();
        void walkClean(DirectoryScope *dir);
        void clean();
        string mCdCmd="$";
        string mLsCmd="ls";
        vector <uint32_t> mAllSizes;
        uint32_t mSize;
        DirectoryScope* mPtrFs, *mNext;
};
        