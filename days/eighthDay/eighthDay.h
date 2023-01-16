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

        enum Directions
        {
            Left,
            Right,
            Up,
            Down
        };
        
        struct TreeStorage
        {
            int treeHeight;
            bool isHeighest;
            TreeStorage(int height) 
            : treeHeight(height)
            , isHeighest(false)
            {

            }
            TreeStorage(int height, bool heighest) 
            : treeHeight(height)
            , isHeighest(heighest)
            {
            }
        
        };

        EighthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
        void countEdges();
        void checkAxises();
        void iterateFrontWay();
        void iterateBackWay();
        void collectIndexes();
        void turnForest();
        void lookForHighestScenicSpot();
        void calculateScenicScore(int & rowIndex, int & colIndex);
        
        vector<vector<TreeStorage>> mForest;
        uint mBestSpot = 1;
        int mVisibleTrees;
        
    
};
        