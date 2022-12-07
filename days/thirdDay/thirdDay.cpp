#include "thirdDay.h"

void ThirdDay::doWork()
{
    vector<set<char>> group;
    for(auto it = mBuckets.begin(); it != mBuckets.end(); it++)
    {
        splitUp(*it);
        makeGroups(*it, group);
    }
    calculateSummaries();
    //clear container because dont need anymore the memory 
    mBuckets.clear();
    printResults();
    
}

void ThirdDay::printResults()
{
    cout << "The sum of these items is:\t" << mSummary <<endl;
    cout << "The sum of these groups is:\t" << mSummaryOfGroups <<endl;
}

int ThirdDay::getSummary() const
{
    return mSummary;
}

void ThirdDay::splitUp(string& line)
{
    string firstHalf = line.substr(0, line.length()/2);
    string secondHalf = line.substr(line.length()/2);
    set<char> pattern;
    set<char> pattern2;
    for(auto ch : firstHalf)
    {
        pattern.insert(ch);
    }
        
    for(auto ch : secondHalf)
    {
        pattern2.insert(ch);
    }
    
    getDuplicateItem(pattern, pattern2);
}

void ThirdDay::getDuplicateItem(const set<char>& pattern1, const set<char>& pattern2)
{
    for(auto ch: pattern1)
    {
        if(pattern2.find(ch)!= pattern2.end())
        {
            mDuplicatedItem.push_back(ch);
        }
    }
}
    
// Lowercase item types a through z have priorities 1 through 26.
// Uppercase item types A through Z have priorities 27 through 52.
void ThirdDay::calculateSummaries()
{
    const int extractFromCapitalA=38;
    const int extractFromSmallA=96;
    for(auto ch : mDuplicatedItem)
    {
        mSummary = isupper(ch) ? mSummary + (ch-extractFromCapitalA) : mSummary + (ch-extractFromSmallA); 
    }
    for(auto ch : mDuplicatedItemByGroups)
    {
        mSummaryOfGroups = isupper(ch) ? mSummaryOfGroups + (ch-extractFromCapitalA) : mSummaryOfGroups + (ch-extractFromSmallA); 
    }

}

void ThirdDay::makeGroups(const string& line, vector<set<char>>& group)
{
    set<char> lineByChars;
    for(auto ch : line)
    {
        lineByChars.insert(ch);
    }
        
    group.push_back(lineByChars);
    if(group.size() == FULL_OF_GROUP)
    {
        for(auto ch: group[FIRST_GROUP])
        {
            if(group[SECOND_GROUP].find(ch) != group[SECOND_GROUP].end())
            {
                if(group[THIRD__GROUP].find(ch) != group[THIRD__GROUP].end())
                {
                    mDuplicatedItemByGroups.push_back(ch);
                }
            }
        }
        group.clear();
    }
}

void ThirdDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;
    
    while(getline(inputFile, line)) 
    {
        mBuckets.push_back(line);
    }
    inputFile.close();    
}