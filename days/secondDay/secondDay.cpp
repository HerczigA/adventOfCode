#include "secondDay.h"

void SecondDay::doWork() {
    encryptingStrategy();
    decryptingStrategy();
    printResults();
}

multimap<string,string> SecondDay::getResults() const {
    return mResults;    
}

void SecondDay::encryptingStrategy() {
    mEncryptedSummary = 0;
    for(auto& it: mResults)
    {
        if(it.first == "A" )
        {
            if(it.second == "X")
            {
                mEncryptedSummary += (RESULTS::DRAWN + mEncryptedProps["X"]);
            }
            else if(it.second == "Y")
            {
                mEncryptedSummary += (RESULTS::WIN + mEncryptedProps["Y"]);
            }
            else
            {
                mEncryptedSummary += (RESULTS::LOOSE + mEncryptedProps["Z"]);
            }
        }
        else if (it.first == "B")
        {
            if(it.second == "X")
            {
                mEncryptedSummary += (RESULTS::LOOSE + mEncryptedProps["X"]);
            }
            else if(it.second == "Y")
            {
                mEncryptedSummary += (RESULTS::DRAWN + mEncryptedProps["Y"]);
            }
            else
            {
                mEncryptedSummary += (RESULTS::WIN + mEncryptedProps["Z"]);
            }
        }
        else
        {
            if(it.second == "X")
            {
                mEncryptedSummary += (RESULTS::WIN + mEncryptedProps["X"]);
            }
            else if(it.second == "Y")
            {
                mEncryptedSummary += (RESULTS::LOOSE + mEncryptedProps["Y"]);
            }
            else
            {
                mEncryptedSummary += (RESULTS::DRAWN + mEncryptedProps["Z"]);
            }
        }
    }    
}

void SecondDay::decryptingStrategy() {
    mDecryptedSummary = 0;
    for(auto& it: mResults)
    {
        if(it.first == "A" )
        {
            if(it.second == "X") //loose to me
            {
                mDecryptedSummary += (RESULTS::LOOSE + mDecryptedProps["Z"]);
            }
            else if(it.second == "Y") // draw
            {
                mDecryptedSummary += (RESULTS::DRAWN + mDecryptedProps["X"]);
            } 
            else // win to me
            {
                mDecryptedSummary += (RESULTS::WIN + mDecryptedProps["Y"]);
            }
        }
        else if (it.first == "B")
        {
            if(it.second == "X")
            {
                mDecryptedSummary += (RESULTS::LOOSE + mDecryptedProps["X"]);
            }
            else if(it.second == "Y")
            {
                mDecryptedSummary += (RESULTS::DRAWN + mDecryptedProps["Y"]);
            }
            else
            {
                mDecryptedSummary += (RESULTS::WIN + mDecryptedProps["Z"]);
            }
        }
        else
        {
            if(it.second == "X")
            {
                mDecryptedSummary += (RESULTS::LOOSE + mDecryptedProps["Y"]);
            }
            else if(it.second == "Y")
            {
                mDecryptedSummary += (RESULTS::DRAWN + mDecryptedProps["Z"]);
            }
            else
            {
                mDecryptedSummary += (RESULTS::WIN + mDecryptedProps["X"]);
            }
        }
    }    
}
void SecondDay::printResults() {
    if(mEncryptedSummary)
        cout << "The summary of the gameset is: " << mEncryptedSummary << endl;    
    else
        cout << "There was some problem because value is 0" << endl;

    if(mDecryptedSummary)
        cout << "The summary of the gameset is: " << mDecryptedSummary << endl;    
    else
        cout << "There was some problem because value is 0" << endl;
}

void SecondDay::getInput(string& filePath) {
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;
    
    while(getline(inputFile, line)) 
    {
        string first, second;
        first = line[0];
        second = line[2];
        mResults.insert(pair<string, string>(first, second));
    }
    inputFile.close();
        
}
