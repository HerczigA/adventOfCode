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
        void doWork(void *param) override;
        void printResults() override;
        int getSummary() const;
        
        vector<string> getMeasurments() const;

    private:
        void splitUp(string& line);
        void getDuplicateItem(const set<char>& pattern1, const set<char>& pattern2);
        void calculateSummaries();
        void makeGroups(const string& line, vector<set<char>>& group);
        int mSummary;
        int mSummaryOfGroups;
        int mMeasursWithNoise;
        int mGroupCounter;
        // vector<vector<set<char>>> mGroups;
        vector<char> mDuplicatedItem;
        vector<char> mDuplicatedItemByGroups;
};