#pragma once 
#include "utils.h" 

class NinthDay : public Days 
{
    public:
        NinthDay();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
    
};
        