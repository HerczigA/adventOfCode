#include "./utils.h"

int Days::openInput(string& file, ifstream& inputFile)
{   
    inputFile.open(file, ios::in);
    if(!inputFile.is_open()) {
      perror("Error open");
      return -1;
    }

    return 0;
}
