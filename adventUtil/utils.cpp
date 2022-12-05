#include "./utils.h"

string& Days::getFileName(int index)
{
    return mAdventInputs[index];
}

int Days::openInput(string& file, ifstream& myfile)
{
    
    myfile.open(file, ios::in);
    if(!myfile.is_open()) {
      perror("Error open");
      return -1;
    }
    
    return 0;
}


void Days::getInput(string& filePath, vector<int>& data)
{
    int result;
    ifstream myfile;
    string line;
    result = openInput(filePath, myfile);
    if(result)
        return;
    while(getline(myfile, line)) {
        data.push_back(atoi(line.c_str()));
    }
    myfile.close();
    
}

void Days::getInput(string& filePath, multimap<string, string>& data)
{
    int result;
    ifstream myfile;
    string line;
    result = openInput(filePath, myfile);
    if(result)
        return;
    while(getline(myfile, line)) {
        string first, second;
        first = line[0];
        second = line[2];
        data.insert(pair<string, string>(first, second));
    }
    myfile.close();
}