#pragma once 
#include "utils.h" 

class NinthDay : public Days 
{
    public:
        
     struct Input{
        string dir;
        int step;
     };
     struct Position
        {
            int x;
            int y;
            Position()
            : x(0)
            , y(0)
            { }
            
            bool operator<(const Position& pos) const
            {
                if(x == pos.x)
                    return y < pos.y;
                else
                    return x < pos.x;
            }
        };
        NinthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void convertInput(string &line);
        void printResults() override;
        // bool isHeadOnTail();
        void iterateTailFirstPart(Input& pos);
        void iterateTailSecondPart(Input& pos);
        void iterateDirectionX(Input& pos);
        void iterateDirectionY(Input& pos);
        // set<string> mCoordinates;
        set<Position> mCoordinates;
        Position mPositionT;
        Position mPositionH;
        list<Input> mPoints;
        
};