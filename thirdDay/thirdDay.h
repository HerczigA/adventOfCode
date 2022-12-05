#pragma once
#include "../adventUtil/utils.h"

class ThirdDay : public Days
{
    public:
        ThirdDay()
        : mSummary(0)
        {

        };
        ~ThirdDay(){};
        void doWork(void *param) override;
        void printResults() override;
        int getSummary() const;
        // int getResWithNoise() const;
        vector<string> getMeasurments() const;

    private:
        void splitUp(string& line);
        void getDuplicateItem(const set<char>& pattern1, const set<char>& pattern2);
        void calculateSummary();
        int mSummary;
        int mMeasursWithNoise;
        vector<string> mItems;
        vector<char> mDuplicatedItem;
};