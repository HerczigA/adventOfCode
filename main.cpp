#include "adventUtil/utils.h"
#include "firstDay/firstDay.h"
#include "secondDay/secondDay.h"

// second part 2 wrong 14431

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


    
    return 0;
}