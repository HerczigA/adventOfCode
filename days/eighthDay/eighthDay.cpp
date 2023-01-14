#include "eighthDay.h"

const int minSize = 0;
const int maxSize = 9;
const int asciiTable = 48;

// 1036 is too low

EighthDay::EighthDay()
    : mVisibleTrees(0)
{

}

void EighthDay::doWork()
{
    countEdges();
    for(int axis = Axis::X; axis <= Axis::Y; axis++)
    {
        for(int view = Direction::front; view <= Direction::reverse; view++)
        {
            map<int, vector<int>> & treeIndexes = axis == Axis::X ? mVisibleTreeIndex : mRotatedVisibleTreeIndex;
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
        vector<int> row;
        auto it = line.begin();
        
        for(int i = 0; i < line.length() -1; i++)
        {
            int height = static_cast<int>(line[i]) - asciiTable;
            row.push_back(height);
        }
        mForest.push_back(row);
    }
    inputFile.close();
}
        
void EighthDay::countEdges()
{
    auto it = mForest.begin();
    int xLen = it->size();
    int yLen = mForest.size()-2;
    mVisibleTrees = 2*(xLen +yLen);
}

void EighthDay::checkAxis(map<int, vector<int>> & visibleTreeIndexes, int &isFront)
{
    int rowIndex = 1;
    auto rowIt = next(mForest.begin());
    auto beforeEndIt = next(mForest.begin(), mForest[0].size()-1);
    while(rowIt != beforeEndIt)
    {
        
        vector<int> visibleTreeCoordinate;
        if(isFront == Direction::front)
            iterateFrontWay(rowIt, visibleTreeCoordinate);
        else
            iterateBackWay(rowIt, visibleTreeIndexes, rowIndex);
        
        visibleTreeIndexes.insert({rowIndex, visibleTreeCoordinate});
        rowIt++;
        rowIndex++;
    }
}

void EighthDay::iterateFrontWay(vector<vector<int>>::iterator & rowIt, vector<int> &visibleTreeCoordinate)
{
    int highestTree = rowIt->at(0);
    for(int idx = 1; idx < rowIt->size()-1; idx++)
    {
        if(highestTree < rowIt->at(idx))
        {
            highestTree = rowIt->at(idx);
            visibleTreeCoordinate.push_back(idx);
        }
        if(highestTree == maxSize)
            break;
    }
    if(visibleTreeCoordinate.size() ==0)
        visibleTreeCoordinate.push_back(-1);
}

void EighthDay::iterateBackWay(vector<vector<int>>::iterator & rowIt, map<int, vector<int>> & visibleTreeIndexes, int &rowIndex)
{
    int highestTree = rowIt->at(rowIt->size()-1);
    for(int idx = rowIt->size()-2; 0 < idx; idx--)
    {
        if(highestTree < rowIt->at(idx))
        {

            if(count(visibleTreeIndexes[rowIndex].begin(), visibleTreeIndexes[rowIndex].end(), idx) == 0)
            {
                auto it = find(visibleTreeIndexes[rowIndex].begin(), visibleTreeIndexes[rowIndex].end(), -1);
                if(it != visibleTreeIndexes[rowIndex].end())
                    visibleTreeIndexes[rowIndex].erase(it);
                visibleTreeIndexes[rowIndex].push_back(idx);
            }
             
            
            highestTree = rowIt->at(idx);
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
    // add some try catch logic 
    vector<vector<int>> rotatedForrest;
    for(int i = mForest[0].size()-1; 0 <= i; i--)
    {
        vector<int> newRow;
        for(auto it : mForest)
            newRow.push_back(it.at(i));
        rotatedForrest.push_back(newRow);
    }
    mForest = rotatedForrest;
}

void EighthDay::compareTreeIndexes()
{
    
        // for(auto colIt : mRotatedVisibleTreeIndex)
        // {
            for(int i = 1; i <= mRotatedVisibleTreeIndex.size(); i++)
            {
                for(int j = 0; j < mRotatedVisibleTreeIndex[i].size(); j++)
                {
                    int idx = mRotatedVisibleTreeIndex[i][j];
                    const int pos = mForest[0].size()-1 -i;
                    if(find(mVisibleTreeIndex[idx].begin(), mVisibleTreeIndex[idx].end(), pos) == mVisibleTreeIndex[idx].end()) //mRotatedVisibleTreeIndex
                        mVisibleTreeIndex[idx].push_back(idx);
                }
            }
            
        // }
    
    collectIndexes();
}