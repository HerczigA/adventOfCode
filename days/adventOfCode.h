#include "utils.h"
#include "firstDay.h"
#include "secondDay.h"
#include "thirdDay.h"
#include "fourthDay.h"
#include "fifthDay.h"
#include "sixthDay.h"
#include "seventhDay.h"
#include "eighthDay.h"
#include "ninthDay.h"

#ifdef RELEASE_AOC
    const string inputPath="../adventUtil/";
#else
    const string inputPath="./adventUtil/";
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
                    inputPath + "inputFirstDay.txt",
                    inputPath + "inputSecondDay.txt",
                    inputPath + "inputThirdDay.txt",
                    inputPath + "inputFourthDay.txt",
                    inputPath + "inputFifthDay.txt",
                    inputPath + "inputSixthDay.txt",
                    inputPath + "inputSeventhDay.txt",
                    inputPath + "inputEighthDay.txt",
					inputPath + "inputNinthDay.txt",
                    #if USE_PROBE_FILE
                    inputPath + "/probe.txt"
                    #endif
        };
};