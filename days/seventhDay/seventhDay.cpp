#include "seventhDay.h"

// 1185273 wrong
// 573235 too low
// 1629598 too much
SeventhDay::SeventhDay()
    : mTotalSize(0)
{
    mPtrFs = nullptr;
    mNext = nullptr; 
}

void SeventhDay::doWork()
{
    
    // int idx, mainFolderIdx = 0;
    // for(auto it = mPtrFs->dirNames.begin(); it != mPtrFs->dirNames.end(); it++)
    // {
    //     mNext = mPtrFs->subDirs[mainFolderIdx]->subDirs ?  *mPtrFs->subDirs[mainFolderIdx]->subDirs : mPtrFs->subDirs[mainFolderIdx];
        
    //     while(mNext != mPtrFs->subDirs[mainFolderIdx])
    //     {
    //         idx = 0;
    //         for(auto dirIt = mNext->head->dirNames.begin(); dirIt != mNext->head->dirNames.end(); dirIt++)
    //         {
    //             if(mNext->head->subDirs[idx]->subDirs)
    //                 walk(*mNext->head->subDirs[idx]->subDirs);
    //             // else
    //             aggregateFileSize(mNext->head->subDirs[idx]);
    //             idx++;
    //         }
    //         mNext = mNext->head;   
    //     }
    //     mainFolderIdx++;
    //     aggregateFileSize(mNext);
    // }

    // clean();

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

    createOs(line, inputFile);
}

// int SeventhDay::createDir(string& line)
// {
//     string newDir = line.substr(DIR_LENGTH_CUTOFF+1);
//     if(mPtrFs)
//     {
//         DirectoryScope *subDir = new DirectoryScope(newDir);
//         if(subDir)
//         {   
//             if(!mNext->subDirs)
//             {
//                 mNext->subDirs = new DirectoryScope*[mNext->dirNames.size()];
//                 if(!mNext->subDirs)
//                 {
//                     cout << "Error: no memory for allocate new DirectoryScope type" <<endl;
//                     delete subDir;
//                     return 1;
//                 }
//             }
//             mNext->subDirs[mNext->actualSubDirIndex++] = subDir;
//             subDir->head = mNext;
//             subDir->name = newDir;
//             mNext = subDir;
//         }
//     }
//     else
//     {
//         mPtrFs = new DirectoryScope(newDir);
//         if(!mPtrFs)
//             return 1;
//         mNext = mPtrFs;
//         mPtrFs->name = newDir;
//     }
//     return 0;
// }

// void SeventhDay::aggregateFileSize(DirectoryScope *dir)
// {
//     if(!dir)
//         return;

//     uint32_t dirSize = dir->subDirs ? dir->dirSize + dir->subDirs[0]->dirSize : dir->dirSize;

//     if(dirSize <= minSize)
//     {
//         mAllSizes.push_back(dirSize);
//         mTotalSize += dirSize;
//     }
//     else if(dirSize <= minSize)
//         mTotalSize += dirSize;

// }

uint32_t SeventhDay::sumOfDirectoriesAtMost100000()
{
    uint32_t result = 0;
    for(auto it: mAllSizes)
        result += it;
    return result;
}

void SeventhDay::parseFile(string & line)
{
    uint32_t dirSize = atoi(line.c_str());
    mNext->dirSize += dirSize; 
}

void SeventhDay::parseDir(string & line)
{
    string dirName =  line.substr(DIR_LENGTH_CUTOFF);
    mNext->dirNames.insert(dirName);
}

// void SeventhDay::walk(DirectoryScope *dir)
// {
//     int idx = 0;
//     for(auto it = dir->head->dirNames.begin() ; it != dir->head->dirNames.end(); it++)
//     {
//         // cout << "check dir->head->subDirs[" << idx << "]->: " << *dir->head->subDirs[idx]->subDirs << endl;
//         if(dir->head->subDirs[idx]->subDirs)
//             walk(*dir->head->subDirs[idx]->subDirs);
//         aggregateFileSize(dir->head->subDirs[idx]);
        
//         idx++;
//     }
//     dir = dir->head;
// }

// void SeventhDay::cleanBranches(DirectoryScope *dir)
// {
//     int idx = 0;
//     for(auto it = dir->head->dirNames.begin() ; it != dir->head->dirNames.end(); it++)
//     {
//         if(dir->head->subDirs[idx]->subDirs)
//             cleanBranches(*dir->head->subDirs[idx]->subDirs);
//         delete dir->head->subDirs[idx];
//         dir->head->subDirs[idx++] = nullptr;
//     }
//     dir = dir->head;
// }

// void SeventhDay::clean()
// {
    
//     uint64_t szar = 0;
    
//     cout<< "all amount "<< sumOfDirectoriesAtMost100000() <<endl;    
//     cout<< "Cleaning..." <<endl;
//     int idx, mainFolderIdx = 0;
//     for(auto it = mPtrFs->dirNames.begin(); it != mPtrFs->dirNames.end(); it++)
//     {
//         mNext = mPtrFs->subDirs[mainFolderIdx];
//         if(mNext->subDirs)
//             mNext=*mNext->subDirs;

//         while(mNext != mPtrFs->subDirs[mainFolderIdx])
//         {
//             idx = 0; 
//             for(auto dirIt = mNext->head->dirNames.begin(); dirIt != mNext->head->dirNames.end(); dirIt++)
//             {
//                 if(mNext->head->subDirs[idx]->subDirs)
//                     cleanBranches(*mNext->head->subDirs[idx]->subDirs);
//                 if(mNext->head->subDirs[idx])
//                     delete  mNext->head->subDirs[idx];
//                 mNext->head->subDirs[idx++] = nullptr;
//             }
//             mNext = mNext->head;   
//         }
        
//         delete mPtrFs->subDirs[mainFolderIdx];
//         mPtrFs->subDirs[mainFolderIdx++] = nullptr;
//     }

//     delete[] mPtrFs->subDirs;
//     mPtrFs->subDirs = nullptr;
// }


void SeventhDay::createOs(string & line, ifstream & inputFile)
{
    while(getline(inputFile, line))
    {
        if(line.find(mCdCmd) != string::npos)
        {
            if(line == "$ cd ..")
                {
                    // mNext = mNext->head;
                }
            else if(line.find( "$ cd") != string::npos)
            {
                // if(createDir(line))    
                // {
                //     clean();
                //     inputFile.close();
                //     return;
                // }
            }
        }
        else if(isdigit(line[0]))
            parseFile(line);
        else
            parseDir(line);
    }
    inputFile.close();
}
