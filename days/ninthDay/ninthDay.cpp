#include "ninthDay.h"

NinthDay::NinthDay()
{

}

void NinthDay::doWork()
{

    printResults();
}

void NinthDay::printResults()
{

}

void NinthDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    MotionSeries motion;
    result = openInput(filePath, inputFile);
    
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        motion.direction = line[0];
        motion.steps = line[2];
        mPoints.push_back(motion);
    }
    inputFile.close();
}
        