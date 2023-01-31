#include "ninthDay.h"

// 3140 too low
NinthDay::NinthDay()
    : mPositionT(Position())
    , mPositionH(Position())
{
    
    mCoordinates.insert({"0-0"});
}

void NinthDay::doWork()
{
    for(auto coordinate : mPoints)
        iterateTail(coordinate);
        
    printResults();
}

void NinthDay::printResults()
{
    cout << "Result of ninth day first part: " << mCoordinates.size() << endl;
}

void NinthDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    
    result = openInput(filePath, inputFile);
    
    if(result)
        return;

    while(getline(inputFile, line)) 
        convertInput(line);
    inputFile.close();
}

void NinthDay::convertInput(string &line)
{
    Input input;
    input.dir = line[0];
    line = line.substr(2);
    input.step = atoi(line.c_str());
    mPoints.push_back(input);
}

void NinthDay::iterateTail(Input& pos)
{
    if(pos.dir == "R" || pos.dir == "L")
        iterateDirectionX(pos);
    else
        iterateDirectionY(pos);
    
}

void NinthDay::iterateDirectionX(Input& pos)
{
    auto stepDirHorizontally = [&](Position& knot){
        if(pos.dir == "R")
            knot.x++;
        else
            knot.x--;
    };
    string coordinate;
    for(int i = 0; i < pos.step; i++)
    {
        stepDirHorizontally(mPositionH);
        if(mPositionH.x == mPositionT.x)
            continue;

        if((mPositionH.x == mPositionT.x-1 || mPositionH.x == mPositionT.x+1))
            continue;
        else if(mPositionH.x == mPositionT.x-2 || mPositionH.x == mPositionT.x+2)
        {
            if(mPositionH.y ==  mPositionT.y + 1)
                mPositionT.y++;
            else if ( mPositionH.y == mPositionT.y - 1)
                mPositionT.y--;

            stepDirHorizontally(mPositionT);
            
        }
        coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
        mCoordinates.insert({coordinate});
    }
}

void NinthDay::iterateDirectionY(Input& pos)
{
    string coordinate;
    auto stepDirVetically = [&](Position& knot){
        if(pos.dir == "U")
            knot.y++;
        else
            knot.y--;
    };
    
    for(int i = 0; i < pos.step; i++)
    {
        stepDirVetically(mPositionH);
        if(mPositionH.y == mPositionT.y)
            continue;

        if((mPositionH.y == mPositionT.y-1 || mPositionH.y == mPositionT.y+1))
            continue;
        else if(mPositionH.y == mPositionT.y-2 || mPositionH.y == mPositionT.y+2)
        {
            if(mPositionH.x ==  mPositionT.x + 1)
                mPositionT.x++;
            else if ( mPositionH.x == mPositionT.x - 1)
                mPositionT.x--;

            stepDirVetically(mPositionT);
            
        }
        coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
        mCoordinates.insert({coordinate});
    }
}