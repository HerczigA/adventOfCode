#include "sixthDay.h"

#ifndef DIFF_CHARS_NUM_FOR_PACKET_MARKER
    #define DIFF_CHARS_NUM_FOR_PACKET_MARKER 4
#endif

#ifndef DIFF_CHARS_NUM_FOR_MESSAGE_MARKER
    #define DIFF_CHARS_NUM_FOR_MESSAGE_MARKER 14
#endif

SixthDay::SixthDay()
    : mPacketMarkerPos(0)
    , mMessageMarkerPos(0)
{

}

void SixthDay::doWork()
{
    findMarkerByType(MARKER_TYPE::PACKET);
    findMarkerByType(MARKER_TYPE::MESSAGE);
    
    printResults();
}

void SixthDay::printResults()
{
    cout << "First packet marker occured at position : " << mPacketMarkerPos << endl;
    cout << "First message marker occured at position : " << mMessageMarkerPos << endl;
}

void SixthDay::getInput(string& filePath)
{
    
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        mDataStream += line;
    }
   
    inputFile.close();
}

bool SixthDay::movingWindowForMarker(string& pattern, int &markerType)
{
    set<char> chars;
    for(auto it = pattern.begin(); it != pattern.end(); it++)
        chars.insert(*it);
    return chars.size() == markerType ? true : false;
}

void SixthDay::findMarkerByType(int type)
{
    string pattern;
    int counter = 0;
    int typeLength = type == MARKER_TYPE::PACKET ? 
            DIFF_CHARS_NUM_FOR_PACKET_MARKER
        :   DIFF_CHARS_NUM_FOR_MESSAGE_MARKER;

    pattern = mDataStream.substr(counter, typeLength);
    while(!movingWindowForMarker(pattern, typeLength))
    {
        counter++;
        pattern = mDataStream.substr(counter, typeLength);
    }
    if(typeLength == DIFF_CHARS_NUM_FOR_PACKET_MARKER)
        mPacketMarkerPos = counter + typeLength;
    else
        mMessageMarkerPos = counter + typeLength;
}