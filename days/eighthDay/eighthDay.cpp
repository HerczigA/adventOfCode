#include "eighthDay.h"

const int minSize = 0;
const int maxSize = 9;
const int asciiTable = 48;

// 1036 is too low
// 1829

EighthDay::EighthDay()
    : mVisibleTrees(0)
{

}

void EighthDay::doWork()
{
    countEdges();
    for( int axes = Axis::X; axes <= Axis::Y ; axes++)
    {
        checkAxises();
        turnForest();
    }
    collectIndexes();
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
        vector<TreeStorage> row;
        auto it = line.begin();
        
        for(int i = 0; i < line.length() -1; i++)
        {
            int height = static_cast<int>(line[i]) - asciiTable;
            TreeStorage tree(height);
            row.push_back(tree);
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


void EighthDay::checkAxises()
{
    iterateFrontWay();
    iterateBackWay();
}


void EighthDay::iterateFrontWay()
{
    int highestTree;
    for(int i = 1; i < mForest.size() -1; i++ )
    {
        highestTree = mForest[i][0].treeHeight;
        for( int j = 1; j <mForest[i].size() -1; j++)
        {
            if(highestTree < mForest[i][j].treeHeight)
            {
                highestTree = mForest[i][j].treeHeight;
                if(mForest[i][j].isHeighest == false)
                    mForest[i][j].isHeighest = true;
            }
            if(highestTree == maxSize)
                break;
        }
    }
}

void EighthDay::iterateBackWay()
{
    int highestTree;
    for(int i = 1; i < mForest.size() -1; i++ )
    {
        highestTree = mForest[i][mForest[i].size()-1].treeHeight;
        for( int j = mForest[i].size() -2; 0 < j; j--)
        {
            if(highestTree < mForest[i][j].treeHeight)
            {
                highestTree = mForest[i][j].treeHeight;
                if(mForest[i][j].isHeighest == false)
                    mForest[i][j].isHeighest = true;
            }
            if(highestTree == maxSize)
                break;
        }
        
    }
    
}

void EighthDay::collectIndexes()
{
    for(int i = 1; i < mForest.size() -1; i++ )
    {
        for( int j = mForest[i].size() -2; 0 < j; j--)
        {
            if(mForest[i][j].isHeighest == true)
                mVisibleTrees++;
        }
    }
}

void EighthDay::turnForest()
{
    // add some try catch logic 
    vector<vector<TreeStorage>> rotatedForrest;
    for(int i = mForest[0].size()-1; 0 <= i; i--)
    {
        vector<TreeStorage> newRow;
        for(auto it : mForest)
            newRow.push_back(TreeStorage(it.at(i).treeHeight, it.at(i).isHeighest) );

        rotatedForrest.push_back(newRow);
    }
    mForest = rotatedForrest;
}
