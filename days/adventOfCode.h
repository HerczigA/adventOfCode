#include "utils.h"
#include "firstDay.h"
#include "secondDay.h"
#include "thirdDay.h"
#include "fourthDay.h"
#include "fifthDay.h"
#include "sixthDay.h"

class AdventOfCode
{
    public:
        AdventOfCode();
        ~AdventOfCode();
        void openCalendarWindows();
    private:
        vector<Days*> mDaysGroup;
};