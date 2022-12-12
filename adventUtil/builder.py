#!/usr/bin/python

# import createNewDay as creator
from .createNewDay import CreateNewDay
import argparse as arg
import sys
import os

class Builder():
    def __init__(self, argsNum):
        self.argNum = argsNum
        self.arg_counter = 1
        self.cmd = "cmake -GNinja "
        self.ninja ="ninja"
        self.dirBuild = "build"
        self.dirDebug = "build_debug"
        self.directory = "build"
        self.componentGenerator = None

        self.removeEverything = "rm -r " + self.dirBuild + " " + self.dirDebug
        parser = arg.ArgumentParser(prog = "Builder python", description="""Builder
                                         script for building advent of code and generating new components""")
        # parser.add_argument("-h", "--help", action="store_true")
        parser.add_argument("-c", "--cmake", action="store_true")
        parser.add_argument("-b", "--build", action="store_true")
        parser.add_argument("-d", "--debug", action="store_true")
        parser.add_argument("-r", "--remove", action="store_true")
        parser.add_argument("-mf", "--makefiles", type=str, help="Component for buildin new *>h and *.cpp component")
        self.args = parser.parse_args()
        pass
    
    def runCmake(self, cmd, directory):
        debug = " -DCMAKE_BUILD_TYPE=Debug "
        if "debug" in directory:
            cmd = cmd + debug
        cmd = cmd + " -B" + directory + " ."
        os.system(cmd)

    def building(self):
        dirBuild = "build"
        dirDebug = "build_debug"
        if os.path.exists(dirBuild):
            print("Building in", dirBuild)
            os.chdir(dirBuild)
            os.system(self.ninja)
        elif os.path.exists(dirDebug):
            print("Building in", dirDebug)
            os.chdir(dirDebug)
            os.system(self.ninja)
        else:
            print("There is no build directory")

    def run(self):
        
        if self.argNum == self.arg_counter:
            print("""\n
            Use <python ./build --help> or
            <python ./build -h> to get some
            help about the building script 
            """)
            exit()
        elif self.args.debug:
            self.directory = self.dirDebug
                
        elif self.args.remove:
            os.system(self.removeEverything)
            if self.args.cmake:
                self.runCmake(self.cmd, self.directory)
            if self.args.build:
                self.building()
                
        elif self.args.cmake:
            self.runCmake(self.cmd, self.directory)
            
            if self.args.build:
                self.building()
                
        elif self.args.build:
            self.building()
            
            
        elif self.args.help:
            print("""
            *********************Build.py********************

            It is a simple python script to help easily build
            and compile your project! You have to know it is
            a hobby project and now it is at the begining.
            Try to get ideas and implement to here.
            
            Usage: Add arguments for ./build.py. It can use
            more than one arguments.
            
            Possibilities:
            -c -> It will generate
            cmake scripts and environment for build the project.
            It will generate for ninja not for make.
            
            -b -> If the CMakeLists.txt is proper 
            and the script could generate the important cmake
            files, then the python script try to compile the 
            project with ninja.
            
            -r remove all the unnecessary build 
            files, executable files  and directory(CMakeFiles)

            -d you can build debug version of the software.

            -C -> choose to cross-compile 
            """)
            # exit()
            
    def createComponent(self):
        if self.args.makefiles:
            self.componentGenerator= CreateNewDay(self.args.makefiles)
            self.componentGenerator.createDay()
            

