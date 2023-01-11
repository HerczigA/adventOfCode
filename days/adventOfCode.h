#include "utils.h"
#include "firstDay.h"
#include "secondDay.h"
#include "thirdDay.h"
#include "fourthDay.h"
#include "fifthDay.h"
#include "sixthDay.h"
#include "seventhDay.h"

#ifdef RELEASE_AOC
    const string inputPath="../";
#else
    const string inputPath="./";
#endif


class AdventOfCode
{
    public:
        AdventOfCode();
        ~AdventOfCode();
        void openCalendarWindows();
    private:
        vector<unique_ptr<Days>> mDaysGroup;
        string& getFileName(int index);
        vector<string> mAdventInputs{
                    inputPath + "adventUtil/inputFirstDay.txt",
                    inputPath + "adventUtil/inputSecondDay.txt",
                    inputPath + "adventUtil/inputThirdDay.txt",
                    inputPath + "adventUtil/inputFourthDay.txt",
                    inputPath + "adventUtil/inputFifthDay.txt",
                    inputPath + "adventUtil/inputSixthDay.txt",
                    inputPath + "adventUtil/inputSeventhDay.txt",
                    #if USE_PROBE_FILE
                    inputPath + "adventUtil/probe.txt"
                    #endif
        };
};