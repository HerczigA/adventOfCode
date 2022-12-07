#pragma once 
#include "utils.h"

#ifndef FULLY_OVERLAPPING
    #define FULLY_OVERLAPPING 1
#endif    

using integerArrayPairs = pair<array<int,2>, array<int,2>>;
using fourthDayFormat = vector<integerArrayPairs>;

// first 20 -> 9
// solution is 477 

class FourthDay : public Days
{
    public:
        FourthDay();
        void doWork()  override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
        integerArrayPairs parsingPairs(string& line);
        fourthDayFormat mSectionIDs;
        int mFullyOverlapping;
};