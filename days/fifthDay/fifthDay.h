#pragma once 
#include "utils.h" 

// First part's solution was : RNZLFZSJH
// Second part's solution was : CNSFCGJSM
const int columns = 9;
class FifthDay : public Days 
{
    enum Steps
    {
        MOVE,
        FROM,
        TO,
        STEPS
    };
    public:
        FifthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
        void workingCrateMover9000(vector<int>& moves);
        void workingCrateMover9001(vector<int>& moves);
        void parsingCrates(vector<string>& crates);
        void parsingMovements(string& movement);
        void catEndUpStacks();
        vector<vector<char>> mCrates;
        vector<vector<int>> mMoves;
        string mEndUpStacks;
};
        