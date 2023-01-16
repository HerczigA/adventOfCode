#pragma once
#include "../adventUtil/utils.h"

class ThirdDay : public Days
{
    public:
        enum GROUPS
        {
            FIRST_GROUP,
            SECOND_GROUP,
            THIRD__GROUP,
            FULL_OF_GROUP
        };
        ThirdDay()
        : mSummary(0)
        , mSummaryOfGroups(0)
        , mGroupCounter(0)
        {

        };
        ~ThirdDay(){};
        void doWork() override;
        int getSummary() const;
        void getInput(string& filePath) override;
        vector<string> getMeasurments() const;

    private:
        void printResults() override;
        void splitUp(string& line);
        void getDuplicateItem(const set<char>& pattern1, const set<char>& pattern2);
        void calculateSummaries();
        void makeGroups(const string& line, vector<set<char>>& group);
        int mSummary;
        int mSummaryOfGroups;
        int mMeasursWithNoise;
        int mGroupCounter;
        vector<string> mBuckets;
        vector<char> mDuplicatedItem;
        vector<char> mDuplicatedItemByGroups;
};