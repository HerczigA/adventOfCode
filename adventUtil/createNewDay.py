#!/usr/bin/python
import os
class CreateNewDay():
    def __init__(self, newDay : str = None) -> None:
        self.newHeader = newDay +".h"
        self.newSource = newDay +".cpp"
        self.className = newDay[0].upper() + newDay[1:]
        self.folderName = newDay
        self.openBracket =  "{"
        self.closeBracket = "}"
        self.patternHeader = f"""#pragma once 
#include \"utils.h\" 

class {self.className} : public Days 
{self.openBracket}
    public:
        {self.className}();
        void doWork() override;
        void printResults() override;
        void getInput(string& filePath) override;
    private:
    
{self.closeBracket};
        """
        
        self.patternSource = f"""#include \"{self.newHeader}\"

{self.className}::{self.className}()
{self.openBracket}

{self.closeBracket}

void {self.className}::doWork()
{self.openBracket}

{self.closeBracket}

void {self.className}::printResults()
{self.openBracket}

{self.closeBracket}

void {self.className}::getInput(string& filePath)
{self.openBracket}

{self.closeBracket}
        """
    
    def createHeader(self):
        with open(self.newHeader, 'w') as f:
            f.write(self.patternHeader)

    def createSource(self):
        with open(self.newSource, 'w') as f:
            f.write(self.patternSource)
    
    def createDay(self):
        if self.folderName is None:
            print("Forgot to give argument for component creator")
            return
        
        os.chdir(os.getcwd() +"/days")
        os.mkdir(self.folderName)
        os.chdir(self.folderName)
        
        self.createHeader()
        self.createSource()