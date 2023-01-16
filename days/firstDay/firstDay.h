#pragma once
#include "utils.h"

class FirstDay : public Days{
    public:
        FirstDay()
        : mMeasursWithoutNoise(0)
        , mMeasursWithNoise(0)
        {

        };
        ~FirstDay(){};
        void doWork() override;
        int getResWithoutNoise() const;
        int getResWithNoise() const;
        void getInput(string& filePath) override;
        vector<int> getMeasurments() const;
    private:
        void printResults() override;
        void measureWithoutNoise();
        void measureWithNoise();
        int mMeasursWithoutNoise;
        int mMeasursWithNoise;
        vector<int> mMeasurments;
};
