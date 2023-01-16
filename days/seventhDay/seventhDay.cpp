#include "seventhDay.h"

#ifndef ROOT_PATH
    #define ROOT_PATH "/home"
#endif

const uint32_t minSize=100000;
const uint32_t totalSize=70000000;
const uint32_t updateSize=30000000;
const uint8_t DIR_LENGTH_CUTOFF=5;

SeventhDay::SeventhDay()
    : mTotalSize(0)
{
    mOs.insert({ROOT_PATH, 0});
}

void SeventhDay::doWork()
{
    collectTotalSizeUnder100000();
    collectDirectoriesForGetFreeSpace();
    printResults();
}

void SeventhDay::printResults()
{
    auto it = mAvailableDirs.begin();
    cout<< "Results of sum of at most 100000 size of directories " << mTotalSize  << endl;
    cout<< "Smallest dir for freeing up some space is  " << *it  << endl;
}

void SeventhDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;

    createOs(line, inputFile);
}

void SeventhDay::countDirSize(string & line)
{
    uint32_t dirSize = atoi(line.c_str());
    uint numberOfSlash = count(mPath.begin(), mPath.end(), '/');
    string recentPath = mPath;
    while(numberOfSlash--)
    {
        auto it = mOs.find(recentPath);
        if(it != mOs.end())
            it->second += dirSize;
        recentPath = recentPath.substr(0, recentPath.rfind("/"));
    }
}

void SeventhDay::parseDir(string & line)
{
    string dirName =  line.substr(DIR_LENGTH_CUTOFF);
    mPath += "/" + dirName;
    mOs.insert({mPath, 0});
}

void SeventhDay::stepBack()
{
    //lambda used just for practicing however it can be solved with count()
    uint numberOfSlash = count_if(mPath.begin(), mPath.end(), [&](char c) {return c=='/';});
    if(numberOfSlash == 1)
        mPath = ROOT_PATH;
    else{
        uint pos = mPath.rfind("/");
        mPath = mPath.substr(0, pos);
    }
    
}

void SeventhDay::collectTotalSizeUnder100000()
{
    for(auto & it : mOs)
    {
        if(it.second < minSize)
            mTotalSize += it.second;
    }
}

void SeventhDay::collectDirectoriesForGetFreeSpace()
{
    auto osIt = mOs.find(ROOT_PATH);
    const uint32_t availableFreeSpace = totalSize - osIt->second;
    const uint32_t requiredFreeSpace = updateSize - availableFreeSpace;
    for(auto & it : mOs)
    {
        if(requiredFreeSpace <= it.second )
            mAvailableDirs.insert(it.second);
    }

}

void SeventhDay::createOs(string & line, ifstream & inputFile)
{
    while(getline(inputFile, line))
    {
        if(line.find(mCdCmd) != string::npos)
        {
            if(line == "$ cd ..")
                stepBack();
            else if(line.find( "$ cd") != string::npos and line != "$ cd /")
                parseDir(line);
        }
        else if(isdigit(line[0]))
            countDirSize(line);
        
    }
    inputFile.close();
}
