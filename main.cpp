#include "adventUtil/utils.h"
#include "firstDay/firstDay.h"
#include "secondDay/secondDay.h"
#include "thirdDay/thirdDay.h"

// second part 2 wrong 14431
// third day first result 7875
// third day second result 2479

int main(int argc, char **argv)
{
    string path;
    Days *days;
    
    FirstDay firstDay;
    vector<int> firstResults;
    days=&firstDay;
    path = days->getFileName(0);
    cout << path <<endl;
    days->getInput(path, firstResults);
    days->doWork(&firstResults);
    SecondDay secondDay;
    days=&secondDay;
    multimap<string, string> secondResults;
    path = days->getFileName(1);
    days->getInput(path, secondResults);
    days->doWork(&secondResults);
    ThirdDay thirdDay;
    days = &thirdDay;
    vector<string> thirdResults;
    path = days->getFileName(2);
    days->getInput(path, thirdResults);
    days->doWork(&thirdResults);


    
    return 0;
}