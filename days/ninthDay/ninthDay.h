#pragma once 
#include "utils.h" 

class NinthDay : public Days 
{
    public:
        struct Origo
        {
            int x;
            int y;
            Origo()
            : x(0)
            , y(0)
            {

            }
        };
        struct MotionSeries
        {
            char direction;
            uint8_t steps;
        };
        NinthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
        Origo mOrigo;
        uint mVisitedPoints;
        list<MotionSeries> mPoints;
};
        