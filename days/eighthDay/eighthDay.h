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
        void checkAxis(map<int, vector<int>> & visibleTreeIndexes, int &isFront);
        void iterateFrontWay(vector<vector<int>>::iterator & rowIt, vector<int> &visibleTreeCoordinate);
        void iterateBackWay(vector<vector<int>>::iterator & rowIt, map<int, vector<int>> & visibleTreeIndexes, int &rowIndex);
        void collectIndexes();
        void turnForest();
        void compareTreeIndexes();
        
        vector<vector<int>> mForest;
        int mVisibleTrees;
        map<int, vector<int>> mVisibleTreeIndex;
        map<int, vector<int>> mRotatedVisibleTreeIndex;
    
};
        