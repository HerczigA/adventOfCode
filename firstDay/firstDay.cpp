#include "firstDay.h"

void FirstDay::measureWithoutNoise(const vector<int>& measurments)
{
    int prevMeasurment = measurments[0];
    const auto lastMeasurment = measurments.end();
    for(auto it=measurments.begin(); it< lastMeasurment; it++)
    {
        if(*it > prevMeasurment)
            mMeasursWithoutNoise++;

        prevMeasurment = *it;
    }
}

void FirstDay::measureWithNoise(const vector<int>& measurments)
{
    
    int prevMeasurment = measurments[0] + measurments[1] + measurments[2];
    int actualMeasurment = prevMeasurment;
    const auto lastMeasurment = measurments.size() -2;
    for(int i = 1; i < lastMeasurment; i++)
    {
        actualMeasurment =measurments[i];
        actualMeasurment +=measurments[i+1];
        actualMeasurment +=measurments[i+2];
        if(actualMeasurment > prevMeasurment)
            mMeasursWithNoise++;

        prevMeasurment = actualMeasurment;
    }

}

int FirstDay::getResWithoutNoise() const
{
    return mMeasursWithoutNoise;
}

int FirstDay::getResWithNoise() const
{
    return mMeasursWithNoise;
}

void FirstDay::printResults()
{
    cout << "Measurment has "<< getResWithoutNoise() << " times increased without noise"<<endl;
    cout << "Measurment has "<< getResWithNoise() << " times increased with noise"<<endl;
}

void FirstDay::doWork(void *param) {
    
    if(!param)
        return;
    
    vector<int> *measurements = static_cast<vector<int>*>(param);
    measureWithoutNoise(*measurements);
    measureWithNoise(*measurements);
    printResults();
}


vector<int> FirstDay::getMeasurments() const {
    return mMeasurments;    
}
