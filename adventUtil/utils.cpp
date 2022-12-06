#include "./utils.h"

string& Days::getFileName(int index)
{
    return mAdventInputs[index];
}

int Days::openInput(string& file, ifstream& inputFile)
{   
    inputFile.open(file, ios::in);
    if(!inputFile.is_open()) {
      perror("Error open");
      return -1;
    }

    return 0;
}
