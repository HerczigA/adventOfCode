#include "seventhDay.h"

SeventhDay::SeventhDay()
    : mSize(0)
{
    mPtrFs = nullptr;
    mNext = nullptr; 
}

void SeventhDay::doWork()
{
    
    cout<< "Do work..." << endl;
}

void SeventhDay::printResults()
{

    cout<< "Results..." << endl;
}

void SeventhDay::getInput(string& filePath)
{
    int result;
    ifstream inputFile;
    string line;
    result = openInput(filePath, inputFile);
    if(result)
        return;

    while(getline(inputFile, line)) 
    {
        cout << line << endl;
        if(line.find(mCdCmd) != string::npos)
        {
            if(line == "$ cd ..")
                mNext = mNext->head;
            else if(line.find( "$ cd") != string::npos)
            {
                if(stepInto(line))    
                {
                    clean();
                    inputFile.close();
                    return;
                }
            }
        }
        else if(isdigit(line[0]))
            parseFile(line);
        else //if(line.find("dir") != string::npos)
            parseDir(line);
            
            
    }
    inputFile.close();
    clean();
}
        

int SeventhDay::stepInto(string& line)
{
    string newDir = line.substr(DIR_LENGTH_CUTOFF+1);
    if(line == "$ cd qlnwhq")
        cout << "megjottunk" << endl;
    if(mPtrFs)
    {
        DirectoryScope *subDir = new DirectoryScope(newDir);
        if(subDir)
        {   
            if(!mNext->subDirs)
            {
                mNext->subDirs = new DirectoryScope*[mNext->dirNames.size()];
                if(!mNext->subDirs)
                {
                    cout << "Error: no memory for allocate new DirectoryScope type" <<endl;
                    delete subDir;
                    return 1;
                }
                // *mNext->subDirs[mNext->actualSubDirIndex++] = *subDir;    
            }
            // else
            // *mNext->subDirs[mNext->actualSubDirIndex++] = *subDir;
            
            mNext->subDirs[mNext->actualSubDirIndex++] = subDir;
            subDir->head = mNext;
            subDir->name = newDir;
            mNext = subDir;
            
        }
    }
    else
    {
        mPtrFs = new DirectoryScope(newDir);
        if(!mPtrFs)
            return 1;
        mNext = mPtrFs;
        mPtrFs->name = newDir;
    }
    return 0;
}


bool SeventhDay::checkSize()
{
    if( mSize <= minSize)
        // mAllSizes.emplace_back(mSize);
        mAllSizes.push_back(mSize);
    mSize = 0;
    return true;
}

uint32_t SeventhDay::sumOfDirectoriesAtMost100000()
{
    uint32_t result = 0;
    for(auto it: mAllSizes)
        result += it;
    return result;
}

void SeventhDay::parseFile(string & line)
{
    uint32_t size = atoi(line.c_str());
    mNext->fileSize += size;
    
}

void SeventhDay::parseDir(string & line)
{
    string dirName =  line.substr(DIR_LENGTH_CUTOFF);
    mNext->dirNames.insert(dirName);
}

void SeventhDay::walk()
{

}

void SeventhDay::walkClean(DirectoryScope *dir)
{
    int idx = 0;
    for(auto it = dir->head->dirNames.begin() ; it != dir->head->dirNames.end(); it++)
    {
        if(*it == "fwfhnbc")
            cout<< *it <<endl;
        cout << "deleting folder " << *it <<endl;
        if(dir->head->subDirs[idx]->subDirs)
            walkClean(*dir->head->subDirs[idx]->subDirs);
        delete dir->head->subDirs[idx];
        cout << "deleted folder " << *it <<endl;
        dir->head->subDirs[idx++] = nullptr;
    }
    dir = dir->head;
}

void SeventhDay::clean()
{
    
    cout<< "cleaning" <<endl;
    int idx, mainFolderIdx = 0;
    for(auto it = mPtrFs->dirNames.begin(); it != mPtrFs->dirNames.end(); it++)
    {
        
        mNext = mPtrFs->subDirs[mainFolderIdx];
        if(mNext->subDirs)
            mNext=*mNext->subDirs;

        while(mNext != mPtrFs->subDirs[mainFolderIdx])
        {
            idx = 0; 
            for(auto dirIt = mNext->head->dirNames.begin(); dirIt != mNext->head->dirNames.end(); dirIt++)
            {
                cout << "deleting folder " << *dirIt <<endl;
                if(mNext->head->subDirs[idx]->subDirs)
                    walkClean(*mNext->head->subDirs[idx]->subDirs);
                if(mNext->head->subDirs[idx])
                    delete  mNext->head->subDirs[idx];
                mNext->head->subDirs[idx++] = nullptr;
                cout << "deleted folder " << *dirIt <<endl;
            }
            mNext = mNext->head;   
        }
        
        cout << "deleting main folders " << *it <<endl;
        delete mPtrFs->subDirs[mainFolderIdx];
        mPtrFs->subDirs[mainFolderIdx++] = nullptr;
    }

    delete[] mPtrFs->subDirs;
    mPtrFs->subDirs = nullptr;
}