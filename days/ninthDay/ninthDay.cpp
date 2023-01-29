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
    input.step = static_cast<int>(line[2]) - asciiTable;
    mPoints.push_back(input);
}

void NinthDay::iterateTail(Input& pos)
{
    string coordinate;
    if( pos.dir == "R")
    {
        for(int i = 0; i < pos.step; i++)
        {
            mPositionH.x++;
            //next room 7.sor
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
                mPositionT.x++;
                
            }
            coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
            mCoordinates.insert({coordinate});
        }
    }
    else if (pos.dir == "L")
    {
        for(int i = 0; i < pos.step; i++)
        {
            mPositionH.x--;
            //next room
            if(mPositionH.x == mPositionT.x)
                continue;

            if((mPositionH.x == mPositionT.x-1 || mPositionH.x == mPositionT.x+1))
                continue;
            else if(mPositionH.x == mPositionT.x-2 || mPositionH.x == mPositionT.x+2)
            {
                if(mPositionH.y ==  mPositionT.y + 1)
                    mPositionT.y++;
                else if (mPositionH.y == mPositionT.y - 1)
                    mPositionT.y--;
                mPositionT.x--;    
                
            }
            coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
            mCoordinates.insert({coordinate});
        }

    }
    else if (pos.dir == "U")
    {
        for(int i = 0; i < pos.step; i++)
        {
            mPositionH.y++;
            //next room
            if(mPositionH.y == mPositionT.y)
                continue;

            if((mPositionH.y == mPositionT.y-1 || mPositionH.y == mPositionT.y+1))
                continue;
            else if(mPositionH.y == mPositionT.y-2 || mPositionH.y == mPositionT.y+2)
            {
                if(mPositionH.x ==  mPositionT.x +1)
                    mPositionT.x++;
                else if(mPositionH.x == mPositionT.x - 1)
                    mPositionT.x--;
                mPositionT.y++;    
                
            }
            coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
            mCoordinates.insert({coordinate});
        }
    }
    else
    {
        for(int i = 0; i < pos.step; i++)
        {
            mPositionH.y--;
            //next room
            if(mPositionH.y == mPositionT.y)
                continue;

            if((mPositionH.y == mPositionT.y-1 || mPositionH.y == mPositionT.y+1))
                continue;
            else if(mPositionH.y == mPositionT.y-2 || mPositionH.y == mPositionT.y+2)
            {
                if(mPositionH.x ==  mPositionT.x +1)
                    mPositionT.x++;
                else if ( mPositionH.x == mPositionT.x - 1)
                    mPositionT.x--;
                mPositionT.y--;    
                
            }
            coordinate = to_string(mPositionT.x) + "-" + to_string(mPositionT.y);
            mCoordinates.insert({coordinate});
            
        }
    }
    
}