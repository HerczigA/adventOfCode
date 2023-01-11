#include "seventhDay.h"

SeventhDay::SeventhDay()
    : mTotalSize(0)
{
    mOs.insert({"/home", 0});
}

void SeventhDay::doWork()
{
    for(auto & it : mOs)
    {
        if(it.second < minSize)
            mTotalSize += it.second;
    }
    printResults();
}

void SeventhDay::printResults()
{
    cout<< "Results of sum of at most 100000 size of directories " << mTotalSize  << endl;
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
        mPath = "/home";
    else{
        uint pos = mPath.rfind("/");
        mPath = mPath.substr(0, pos);
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
