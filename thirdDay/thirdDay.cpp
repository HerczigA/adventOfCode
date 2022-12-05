#include "thirdDay.h"


void ThirdDay::doWork(void *param)
{
    if(!param)
        return;
    vector<string> *itemsList = static_cast<vector<string>*>(param);
    for(auto it = itemsList->begin(); it != itemsList->end(); it++)
    {
        splitUp(*it);
    }
    calculateSummary();
    printResults();   
}

void ThirdDay::printResults()
{
    cout << "The sum of these is items is:\t" << mSummary <<endl;
}

int ThirdDay::getSummary() const
{
    return mSummary;
}

void ThirdDay::splitUp(string& line)
{
    string firstHalf = line.substr(0, line.length()/2);
    string secondHalf = line.substr(line.length()/2);
#if DEBUG_ADVENT
    cout <<"length of spliting up line : "<< line.length()<< endl;
    cout <<"first Half : "<< firstHalf<< endl;
    cout <<"second Half : "<< secondHalf<< endl;
#endif
    set<char> pattern;
    set<char> pattern2;
    for(int i = 0; i < firstHalf.length(); i++)
        pattern.insert(firstHalf[i]);
    for(int i = 0; i < secondHalf.length(); i++)
        pattern2.insert(secondHalf[i]);

    getDuplicateItem(pattern, pattern2);
}

void ThirdDay::getDuplicateItem(const set<char>& pattern1, const set<char>& pattern2)
{
    for(auto ch: pattern1)
    {
        if(pattern2.find(ch)!= pattern2.end())
        {
            #if DEBUG_ADVENT
                cout << "Character in getDuplicatedItem\n" << ch <<endl;
            #endif
            mDuplicatedItem.push_back(ch);
        }
            
    }
}
    
// Lowercase item types a through z have priorities 1 through 26.
// Uppercase item types A through Z have priorities 27 through 52.
void ThirdDay::calculateSummary()
{
    const int extractFromCapitalA=38;
    const int extractFromSmallA=96;
    for(auto ch : mDuplicatedItem)
    {
        #if DEBUG_ADVENT
            cout << "it in calculate summary\n"<< ch <<endl;
        #endif
        mSummary = isupper(ch) ? mSummary + (ch-extractFromCapitalA) : mSummary + (ch-extractFromSmallA); 
    }

}