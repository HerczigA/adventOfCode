#pragma once 
#include "utils.h" 

class EighthDay : public Days 
{
    public:
        enum Axis
        {
          X,
          Y
        };
        enum Direction
        {
          front,
          reverse
        };

        EighthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
        void countEdges();
        void checkAxis(map<uint, vector<uint>> & visibleTreeIndexes, int &isFront);
        void iterateFrontWay(vector<vector<uint>>::iterator & rowIt, vector<uint> &visibleTreeCoordinate);
        void iterateBackWay(vector<vector<uint>>::iterator & rowIt, map<uint, vector<uint>> & visibleTreeIndexes, uint &rowIndex);
        void collectIndexes();
        void turnForest();
        void compareTreeIndexes();
        
        vector<vector<uint>> mForest;
        uint mVisibleTrees;
        map<uint, vector<uint>> mVisibleTreeIndex;
        map<uint, vector<uint>> mRotatedVisibleTreeIndex;
    
};
        