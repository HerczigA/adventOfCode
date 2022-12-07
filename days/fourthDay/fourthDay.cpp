#include "fourthDay.h"

FourthDay::FourthDay()
    : mFullyOverlapping(0)
    , mPartlyOverlapping(0)
{
    
}

void FourthDay::doWork()
{
#if DEBUG_ADVENT
    string logName= "./logFourthDay.txt";
    ofstream logFourthDay(logName);
    if( !logFourthDay.is_open())
    {
        cout << "Can not open file for log" << endl;
        return;
    }
#endif    
    for(auto it: mSectionIDs)
    {
        // #if FULLY_OVERLAPPING

            if((it.first[0] <= it.second[0]) && (it.second[1] <= it.first[1]))
            {
                #if DEBUG_ADVENT
                logFourthDay << "\nit.first[0]= "<< it.first[0] << "\t it.second[0]="  << it.second[0] <<"\n";
                logFourthDay << "it.first[1]= "<< it.first[1]<< "\t it.second[1]="  << it.second[1] << "\n";
                logFourthDay << "===============================";
                #endif
                mFullyOverlapping++;
            }
            else if((it.second[0] <= it.first[0]) && (it.first[1] <= it.second[1]))
            {
                #if DEBUG_ADVENT
                logFourthDay << "\nit.second[0]= "<< it.second[0] << "\t it.first[0]="  << it.first[0] <<"\n";
                logFourthDay << "it.second[1]= "<< it.second[1] << "\t it.first[1]="  << it.first[1] << "\n";
                logFourthDay << "===============================";
                #endif
                mFullyOverlapping++;
            }
        // #else
            if(((it.first[0] <= it.second[0] && it.second[0] <= it.first[1])  
            || (it.first[0] <= it.second[1] && it.second[1] <= it.first[1])))
            {
                mPartlyOverlapping++;
            }   
            else if(((it.second[0] <= it.first[0] && it.first[0] <= it.second[1])  
            || (it.second[0] <= it.first[1] && it.first[1] <= it.second[1])))
            {
                mPartlyOverlapping++;   
            }

        // #endif
        
         
    }
    #if DEBUG_ADVENT
        logFourthDay.close();
    #endif
    //clear container because dont need anymore the memory 
    mSectionIDs.clear();
    printResults();
}

void FourthDay::printResults()
{
    // #if FULLY_OVERLAPPING
        cout << "Fully overlapping occured\t "<< mFullyOverlapping << " times"<< endl;
    // #else
        cout << "Overlapping occured\t "<< mPartlyOverlapping << " times"<< endl;
    // #endif
}

void FourthDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        integerArrayPairs pair = parsingPairs(line);
        mSectionIDs.push_back(pair);
    }
    inputFile.close();
}

integerArrayPairs FourthDay::parsingPairs(string& line) {
    string substring;
    int indexScore = line.find('-');
    int indexComma = line.find(',');
    array<int,2> firstPair, secondPair;
    firstPair[0] = abs(atoi(line.c_str()));
    substring = line.substr(indexScore + 1);
    firstPair[1] = abs(atoi(substring.c_str()));
    line = line.substr(indexComma +1 );
    indexScore = line.find('-');
    secondPair[0] = abs(atoi(line.c_str()));
    substring = line.substr(indexScore +1);
    secondPair[1] = abs(atoi(substring.c_str()));
    return  make_pair(firstPair, secondPair);
}