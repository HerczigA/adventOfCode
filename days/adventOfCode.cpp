#include "adventOfCode.h"


AdventOfCode::AdventOfCode() {
    mDaysGroup.push_back(make_unique<FirstDay>());
    mDaysGroup.push_back(make_unique<SecondDay>());
    mDaysGroup.push_back(make_unique<ThirdDay>());
    mDaysGroup.push_back(make_unique<FourthDay>());
    mDaysGroup.push_back(make_unique<FifthDay>());
    mDaysGroup.push_back(make_unique<SixthDay>());
    mDaysGroup.push_back(make_unique<SeventhDay>());
}

AdventOfCode::~AdventOfCode() {
    for(auto &day : mDaysGroup)
    {
        day.reset();
    }
     
}
void AdventOfCode::openCalendarWindows() {
    // unique_ptr<Days> days;
    Days* days;
    string pathOfDayInput;
    for(int day = 0; day != mDaysGroup.size(); day++)
    {
        days = mDaysGroup[day].get();
        if(days)
        {
            pathOfDayInput = getFileName(day);
            days->getInput(pathOfDayInput);
            days->doWork();
        }
    }    
}


string& AdventOfCode::getFileName(int index)
{
    return mAdventInputs[index];
}