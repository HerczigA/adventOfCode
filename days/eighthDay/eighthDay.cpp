#include "eighthDay.h"

const uint minSize = 0;
const uint maxSize = 9;
const uint asciiTable = 48;

// 1036 is too low

EighthDay::EighthDay()
    : mVisibleTrees(0)
{

}

void EighthDay::doWork()
{
    countEdges();
    for(uint axis = Axis::X; axis <= Axis::Y; axis++)
    {
        for(int view = Direction::front; view <= Direction::reverse; view++)
        {
            map<uint, vector<uint>> & treeIndexes = axis == Axis::X ? mVisibleTreeIndex : mRotatedVisibleTreeIndex;
            checkAxis(treeIndexes, view);
        }
        turnForest();
    }
    compareTreeIndexes();
    printResults();
}

void EighthDay::printResults()
{
    cout << "The number of visible trees in the forest are " << mVisibleTrees << endl;
}

void EighthDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        vector<uint> row;
        auto it = line.begin();
        
        for(uint i = 0; i < line.length() -1; i++)
        {
            uint height = static_cast<uint>(line[i]) - asciiTable;
            row.push_back(height);
        }
        mForest.push_back(row);
    }
    inputFile.close();
}
        
void EighthDay::countEdges()
{
    auto it = mForest.begin();
    uint xLen = it->size();
    uint yLen = mForest.size()-2;
    mVisibleTrees = 2*(xLen +yLen);
}

void EighthDay::checkAxis(map<uint, vector<uint>> & visibleTreeIndexes, int &isFront)
{
    uint rowIndex = 1;
    auto rowIt = next(mForest.begin());
    auto beforeEndIt = next(mForest.begin(), mForest[0].size()-1);
    while(rowIt != beforeEndIt)
    {
        
        vector<uint> visibleTreeCoordinate;
        if(isFront == Direction::front)
            iterateFrontWay(rowIt, visibleTreeCoordinate);
        else
            iterateBackWay(rowIt, visibleTreeIndexes, rowIndex);
        
        visibleTreeIndexes.insert({rowIndex, visibleTreeCoordinate});
        rowIt++;
        rowIndex++;
    }
}

void EighthDay::iterateFrontWay(vector<vector<uint>>::iterator & rowIt, vector<uint> &visibleTreeCoordinate)
{
    uint highestTree = rowIt->at(0);
    for(uint idx = 1; idx < rowIt->size()-1; idx++)
    {
        if(highestTree < rowIt->at(idx))
        {
            highestTree = rowIt->at(idx);
            visibleTreeCoordinate.push_back(idx);
        }
        if(highestTree == maxSize)
                break;
    }
}

void EighthDay::iterateBackWay(vector<vector<uint>>::iterator & rowIt, map<uint, vector<uint>> & visibleTreeIndexes, uint &rowIndex)
{
    uint highestTree = rowIt->at(rowIt->size()-1);
    for(uint idx = rowIt->size()-2; 0 < idx; idx--)
    {
        if(highestTree < rowIt->at(idx))
        {
            uint potentialTreeIdx = rowIt->size() - idx -1;
            if(count(visibleTreeIndexes[rowIndex].begin(), visibleTreeIndexes[rowIndex].end(), potentialTreeIdx) == 0)
            {
                highestTree = rowIt->at(idx);
                visibleTreeIndexes[rowIndex].push_back(potentialTreeIdx);
            }
        }
        if(highestTree == maxSize)
            break;
    }
    
}

void EighthDay::collectIndexes()
{
    for(auto it : mVisibleTreeIndex)
        mVisibleTrees += it.second.size();
    
}

void EighthDay::turnForest()
{
    vector<vector<uint>> rotatedForrest;
    for(int i = mForest[0].size()-1; 0 <= i; i--)
    {
        vector<uint> newRow;
        for(auto it : mForest)
            newRow.push_back(it.at(i));
        rotatedForrest.push_back(newRow);
    }
    mForest = rotatedForrest;
}

void EighthDay::compareTreeIndexes()
{
    // TO DO compare logic
    collectIndexes();
}