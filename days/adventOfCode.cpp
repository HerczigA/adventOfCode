#include "adventOfCode.h"


AdventOfCode::AdventOfCode() {
    mDaysGroup.push_back(new FirstDay);
    mDaysGroup.push_back(new SecondDay);
    mDaysGroup.push_back(new ThirdDay);
    mDaysGroup.push_back(new FourthDay);
}

AdventOfCode::~AdventOfCode() {
    for(auto day : mDaysGroup)
        delete day;
}
void AdventOfCode::openCalendarWindows() {
    Days* days;
    string pathOfDayInput;
    for(int day = 0; day != mDaysGroup.size(); day++)
    {
        days = mDaysGroup[day];
        pathOfDayInput = days->getFileName(day);
        days->getInput(pathOfDayInput);
        days->doWork();

    }    
}
