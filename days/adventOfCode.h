#include "utils.h"
#include "firstDay.h"
#include "secondDay.h"
#include "thirdDay.h"
#include "fourthDay.h"
#include "fifthDay.h"
#include "sixthDay.h"
#include "seventhDay.h"

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
                    "../adventUtil/inputFirstDay.txt",
                    "../adventUtil/inputSecondDay.txt",
                    "../adventUtil/inputThirdDay.txt",
                    "../adventUtil/inputFourthDay.txt",
                    "../adventUtil/inputFifthDay.txt",
                    "../adventUtil/inputSixthDay.txt",
                    "../adventUtil/inputSeventhDay.txt",
                    #if USE_PROBE_FILE
                    "../adventUtil/probe.txt"
                    #endif
        };
};