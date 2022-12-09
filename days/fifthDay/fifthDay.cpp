#include "fifthDay.h"

FifthDay::FifthDay()
    : mEndUpStacks("")
{
    for(int i = 1; i <= columns ; i++)
    {
        vector<char> crate;
        mCrates.push_back(crate);
    }
}

void FifthDay::doWork()
{
    char sign;
    int lastElement;
    for(auto& moves : mMoves)
    {

        for(int i = 0; i < moves[MOVE]; i++)
        {
            lastElement = mCrates[moves[FROM]-1].size();
            sign = mCrates[moves[FROM]-1][lastElement-1];
            mCrates[moves[FROM]-1].pop_back();
            mCrates[moves[TO]-1].push_back(sign);
            
        }
    }
    catEndUpStacks();
    printResults();
}

void FifthDay::printResults()
{
    cout << "End up stacks after rearranging\t"<< mEndUpStacks << endl;
}

void FifthDay::getInput(string& filePath)
{
    string firstMove="move";
    int result;
    ifstream inputFile;
    string line;
    vector<string> crates;
    int rackColumns = 8;
    result = openInput(filePath, inputFile);
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        if(rackColumns)
        {
            crates.push_back(line);
            rackColumns--;
        }
        else{
            if(line.find("move") == string::npos)
                continue;
            
            parsingMovements(line);
        }
    }
   
    parsingCrates(crates);
    inputFile.close();

}

void FifthDay::parsingMovements(string& movements) {
    stringstream ssMovements;
    ssMovements << movements;
    vector<int> moves;
    string subMovement;
    int value;
    
    while(!ssMovements.eof()) 
    {
        ssMovements >> subMovement;
        if(stringstream(subMovement) >> value) 
        {
            moves.push_back(value);
        }
    }
    mMoves.push_back(moves);
}
void FifthDay::parsingCrates(vector<string>& crates)
{

    char openBracket = '[';
    int signPos = 0;
    const int crateLength = 4;
    string crateLine;
    
    reverse(crates.begin(), crates.end());

    while(crates.size())
    {
        crateLine=crates[0];
        for(int i = 1; i < crateLine.length(); i += crateLength)
        {
            if(isalpha(crateLine[i]))
            {
                mCrates[i/crateLength].push_back(crateLine[i]);
            }
        }
        crates.erase(crates.begin());
    }
}

void FifthDay::catEndUpStacks()
{
    for(auto& crate : mCrates)
        mEndUpStacks += crate[crate.size()-1];
}