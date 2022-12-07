#include "fourthDay.h"

FourthDay::FourthDay()
    : mFullyOverlapping(0)
{
    
}

void FourthDay::doWork()
{
    string logName= "./logFourthDay.txt";
    ofstream logFourthDay(logName);
    if( !logFourthDay.is_open())
    {
        cout << "Can not open file for log" << endl;
        return;
    }
    int firstOverlaped=0;
    int secondOverlaped=0;
    for(auto it: mSectionIDs)
    {
        #if FULLY_OVERLAPPING

            if((it.first[0] <= it.second[0]) && (it.second[1] <= it.first[1]))
            {
                logFourthDay << "\nit.first[0]= "<< it.first[0] << "\t it.second[0]="  << it.second[0] <<"\n";
                logFourthDay << "it.first[1]= "<< it.first[1]<< "\t it.second[1]="  << it.second[1] << "\n";
                logFourthDay << "===============================";
                mFullyOverlapping++;
                firstOverlaped++;
            }
            else if((it.second[0] <= it.first[0]) && (it.first[1] <= it.second[1]))
            {
                logFourthDay << "\nit.second[0]= "<< it.second[0] << "\t it.first[0]="  << it.first[0] <<"\n";
                logFourthDay << "it.second[1]= "<< it.second[1] << "\t it.first[1]="  << it.first[1] << "\n";
                logFourthDay << "===============================";
                mFullyOverlapping++;
                secondOverlaped++;
            }
        #else
            if(it.first[0] <= it.second[0] || it.first[1] >= it.second[1])
            {
                // cout << "it.first[0]= "<< it.first[0]<< "\tit.second[0]="  << it.second[0] << endl;
                mFullyOverlapping++;
            }   
            else if(it.second[0] <= it.first[0] || it.second[1] >= it.first[1])
            {
                // cout << "it.second[0]= "<< it.second[0]<< "\tit.first[0]="  << it.first[0] << endl;
                mFullyOverlapping++;   
            }

        #endif
        
         
    }
    cout << "first overlaped =\t " << firstOverlaped <<endl;
    cout << "second overlaped =\t " << secondOverlaped <<endl;
    logFourthDay.close();
    //clear container because dont need anymore the memory 
    mSectionIDs.clear();
    printResults();
}

void FourthDay::printResults()
{
    cout << "Fully overlapping occured\t "<< mFullyOverlapping << " times"<< endl;
}

void FourthDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;
    string logName= "./logParsing.txt";
    ofstream logFourthDay(logName);
    if( !logFourthDay.is_open())
    {
        cout << "Can not open file for log" << endl;
        return;
    }
    while(getline(inputFile, line)) 
    {
        integerArrayPairs pair = parsingPairs(line);
        logFourthDay << "\npair.first[0]= "<< pair.first[0] << "\t pair.second[0]="  << pair.second[0] <<"\n";
        logFourthDay << "pair.first[1]= "<< pair.first[1]<< "\t pair.second[1]="  << pair.second[1] << "\n";
        mSectionIDs.push_back(pair);
    }

    logFourthDay.close();

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