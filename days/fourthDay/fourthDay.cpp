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
        cout << "shit" << endl;
        return;
    }
    for(auto it: mSectionIDs)
    {
        #if FULLY_OVERLAPPING
            if(it.first[0] <= it.second[0] && it.second[1] <= it.first[1] 
            || it.second[0] <= it.first[0] && it.first[1] <= it.second[1])
            {
                logFourthDay << "\nit.first[0]= "<< to_string(it.first[0]) << "\t it.second[0]="  << it.second[0] <<"\n";
                logFourthDay << "it.first[1]= "<< it.first[1]<< "\t it.second[1]="  << it.second[1] << "\n";
                logFourthDay << "===============================";
                mFullyOverlapping++;
            }   
            // else if(it.second[0] <= it.first[0] && it.first[1] <= it.second[1])
            // {
            //     logFourthDay << "\nit.second[0]= "<< it.second[0]<< "\t it.first[0]="  << it.first[0] << "\n";
            //     logFourthDay << "it.second[1]= "<< it.second[1]<< "\t it.first[1]="  << it.first[1] << "\n";
            //     logFourthDay << "===============================";
            //     mFullyOverlapping++;   
            // }
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
    logFourthDay.close();
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
    if(!result)
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
    substring = line.substr(indexScore+1, indexComma - indexScore -1);
    firstPair[1] = abs(atoi(substring.c_str()));
    line = line.substr(indexComma+1);
    secondPair[0] = abs(atoi(line.c_str()));
    substring = line.substr(indexScore+1);
    secondPair[1] = abs(atoi(substring.c_str()));
    return  make_pair(firstPair, secondPair);   
}