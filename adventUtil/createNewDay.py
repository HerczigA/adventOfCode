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
        self.inputFile = "intput" + self.className + ".txt"
        self.rootFolder = os.path.abspath(os.getcwd())
        self.patternHeader = f"""\r#pragma once \
                                \r#include \"utils.h\"\n \
                                \rclass {self.className} : public Days \
                                \r{{ \
                                \r\tpublic: \
                                \r\t\t{self.className}(); \
                                \r\t\tvoid doWork() override; \
                                \r\t\tvoid getInput(string& filePath) override; \
                                \r\tprivate: \
                                \r\t\tvoid printResults() override;\n \
                                \r}};"""
        
        self.patternSource = f"""#include \"{self.newHeader}\" \n \

                            \r{self.className}::{self.className}() \
                            \r{{\n \
                            \r}}\n \
                            \rvoid {self.className}::doWork() \
                            \r{{ \
                            \r\tprintResults(); \
                            \r}}\n \
                            \rvoid {self.className}::printResults()\
                            \r{{\n \
                            \r}}\n \
                            \rvoid {self.className}::getInput(string& filePath) \
                            \r{{ \
                            \r\tint result; \
                            \r\tifstream inputFile; \
                            \r\tstring line;\n \
                            \r\tresult = openInput(filePath, inputFile);\n \
                            \r\tif(result) \
                            \r\t\treturn;\n \
                            \r\twhile(getline(inputFile, line)) \
                            \r\t{{\n\n \
                            \r\t}} \
                            \r\tinputFile.close(); \
                            \r}}"""
    
    def createHeader(self):
        if os.path.exists(self.newHeader):
            return
        with open(self.newHeader, 'w') as f:
            f.write(self.patternHeader)

    def createSource(self):
        if os.path.exists(self.newSource):
            return
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
        
        os.chdir(self.rootFolder +"/days")
        if os.path.exists(self.folderName):
            if os.listdir(self.folderName):
                os.remove(self.folderName +"/"+ self.newHeader)
                os.remove(self.folderName +"/"+ self.newSource)
            os.rmdir(self.folderName)    
        os.mkdir(self.folderName)
        os.chdir(self.folderName)
        self.createHeader()
        self.createSource()
        self.updateCMakeLists()
        self.updateAdventOfCode()
        self.createNewInputTxt()
            
    def updateAdventOfCode(self):
        os.chdir(self.rootFolder +"/days")
        self.updateAdventHeader()
        self.updateAdventSource()
    
    def updateAdventHeader(self):
        fileContent = None
        newIncludePath = 5
        newIncludeIdx = 0
        includeHeader = f'#include "{self.newHeader}"\n'
        includePath = f'\t\t\t\t\tinputPath + "input{self.className}.txt",\n'
        with open("./adventOfCode.h", "r") as aocH:
            fileContent = aocH.readlines()
            for line in fileContent:
                if line == "#ifdef RELEASE_AOC\n":
                    newIncludeIdx -= 1
                    break
                newIncludeIdx += 1
                
            fileContent.insert(newIncludeIdx, includeHeader)
            fileContent.insert(len(fileContent)-newIncludePath, includePath)
            with open("./adventOfCode.h", "w") as f:
                fileContent = "".join(fileContent)
                f.write(fileContent)
            pass
        pass
    
    def updateAdventSource(self):
        fileContent = None
        newPushbackIdx = 0
        pushBackNewObject = f"\tmDaysGroup.push_back(make_unique<{self.className}>());\n"
        with open("./adventOfCode.cpp", "r") as aocS:
            fileContent = aocS.readlines()
            for line in fileContent:
                if line.find("}") != -1:
                    break
                newPushbackIdx +=1
            fileContent.insert(newPushbackIdx, pushBackNewObject)
            
        with open("./adventOfCode.cpp", "w") as f:
            fileContent = "".join(fileContent)
            f.write(fileContent)
    
    def createNewInputTxt(self):
        os.chdir(self.rootFolder + "/adventUtil")
        if os.path.exists(self.inputFile):
            return
        with open(self.inputFile, 'w') as f:
            pass
                