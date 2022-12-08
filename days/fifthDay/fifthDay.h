#pragma once 
#include "utils.h" 
#include <sstream>

const int columns = 9;
class FifthDay : public Days 
{
    enum Steps
    {
        MOVE,
        FROM,
        TO
    };
    public:
        FifthDay();
        void doWork() override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
        void parsingCrates(vector<string>& crates);
        void parsingMovements(string& movement);
        vector<vector<char>> mCrates;
        vector<vector<int>> mMoves;
};
        