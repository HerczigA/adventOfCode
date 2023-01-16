#!/usr/bin/python
import os

class CreateNewDay():
    def __init__(self, numberOfDay : int = None) -> None:
        self.days = {}
        self.dayLabels = ["first" ,"second", "third", "fourth",
                          "fifth" ,"sixth", "seventh", "eighth",
                          "ninth" ,"tenth", "eleventh", "twelth",
                          "thirteenth" ,"fourteenth", "fifteenth", "sixteenth",
                          "seventeenth" ,"eighteenth", "nineteenth", "twentieth",
                          "twentyFirst" ,"twentySecond", "twentyThird", "twentyFourth",
                          "twentyFifth"] 
        for i in range(1,26):
            self.days[i] = self.dayLabels[i-1]
            
        self.newHeader = self.days.get(numberOfDay) +"Day.h"
        self.newSource = self.days.get(numberOfDay) +"Day.cpp"
        self.folderName = self.days.get(numberOfDay) +"Day"
        self.className = self.folderName[0].upper() + self.folderName[1:]
        self.openBracket =  "{"
        self.closeBracket = "}"
        self.patternHeader = f"""#pragma once 
#include \"utils.h\" 

class {self.className} : public Days 
{self.openBracket}
    public:
        {self.className}();
        void doWork() override;
        void getInput(string& filePath) override;
    private:
        void printResults() override;
    
{self.closeBracket};
        """
        
        self.patternSource = f"""#include \"{self.newHeader}\"

{self.className}::{self.className}()
{self.openBracket}

{self.closeBracket}

void {self.className}::doWork()
{self.openBracket}

    printResults();
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
    
    def updateCMakeLists(self):
        os.chdir(os.getcwd() +"/../..")
        fileContent = None
        with open("./CMakeLists.txt", "r") as cmakeFile:
            fileContent = cmakeFile.readlines()
            newIncludeDir = fileContent[-3]
            newIncludeDir = newIncludeDir[0 : newIncludeDir.rfind("/") +1]
            newIncludeDir += self.folderName + "\n"
            fileContent.insert(len(fileContent)-2, newIncludeDir)
            
        with open("./CMakeLists.txt", "w") as f:
            fileContent = "".join(fileContent)
            f.write(fileContent)
            
        
    
    def createDay(self):
        if self.folderName is None:
            print("Forgot to give argument for component creator")
            return
        
        os.chdir(os.getcwd() +"/days")
        if not os.path.exists(self.folderName):
            os.mkdir(self.folderName)
            os.chdir(self.folderName)
            self.createHeader()
            self.createSource()
            self.updateCMakeLists()