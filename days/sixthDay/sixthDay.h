#pragma once 
#include "utils.h" 

// first half result = 1647
// second half result = 2447

class SixthDay : public Days 
{
    enum MARKER_TYPE
    {
        PACKET,
        MESSAGE
    };
    public:
        SixthDay();
        void doWork() override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
        bool movingWindowForMarker(string& pattern, int &markerType);
        void findMarkerByType(int type);
        string mDataStream;
        int mPacketMarkerPos;
        int mMessageMarkerPos;
};