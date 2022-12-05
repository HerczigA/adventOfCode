#pragma once
#include "../adventUtil/utils.h"

class FirstDay : public Days{
    public:
        FirstDay()
        : mMeasursWithoutNoise(0)
        , mMeasursWithNoise(0)
        {

        };
        ~FirstDay(){};
        void doWork(void *param) override;
        void printResults() override;
        int getResWithoutNoise() const;
        int getResWithNoise() const;
        vector<int> getMeasurments() const;

    private:
        void measureWithoutNoise(const vector<int>& measurments);
        void measureWithNoise(const vector<int>& measurments);
        int mMeasursWithoutNoise;
        int mMeasursWithNoise;
        vector<int> mMeasurments;
};
