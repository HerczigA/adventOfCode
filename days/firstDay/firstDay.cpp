#include "firstDay.h"

void FirstDay::measureWithoutNoise()
{
    int prevMeasurment = mMeasurments[0];
    const auto lastMeasurment = mMeasurments.end();
    for(auto it=mMeasurments.begin(); it< lastMeasurment; it++)
    {
        if(*it > prevMeasurment)
            mMeasursWithoutNoise++;

        prevMeasurment = *it;
    }
}

void FirstDay::measureWithNoise()
{
    int prevMeasurment = mMeasurments[0] + mMeasurments[1] + mMeasurments[2];
    int actualMeasurment = prevMeasurment;
    const auto lastMeasurment = mMeasurments.size() -2;
    for(int i = 1; i < lastMeasurment; i++)
    {
        actualMeasurment =mMeasurments[i];
        actualMeasurment +=mMeasurments[i+1];
        actualMeasurment +=mMeasurments[i+2];
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

void FirstDay::doWork() {
    measureWithoutNoise();
    measureWithNoise();
    printResults();
}


vector<int> FirstDay::getMeasurments() const {
    return mMeasurments;    
}

void FirstDay::getInput(string& filePath) {
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;
    while(getline(inputFile, line)) 
    {
        mMeasurments.push_back(atoi(line.c_str()));
    }
    inputFile.close();
}
