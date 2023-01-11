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
        parser.add_argument("-c", "--cmake", action="store_true")
        parser.add_argument("-b", "--build", action="store_true")
        parser.add_argument("-d", "--debug", action="store_true")
        parser.add_argument("-r", "--remove", action="store_true")
        parser.add_argument("-D", "--day", type=int, choices=range(1, 26))
        parser.add_argument("-mf", "--makefiles", type=str, help="Component for buildin new *>h and *.cpp component")
        self.args = parser.parse_args()
        pass
    
    def runCmake(self, cmd, directory):
        buildType = ' -DCMAKE_BUILD_TYPE="Release"' if directory == "build" else ' -DCMAKE_BUILD_TYPE="Debug"'
        cmd = cmd + ' -B' + directory + buildType + ' .'
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
            
            -r -> remove all the unnecessary build 
            files, executable files  and directory(CMakeFiles)

            -d -> you can build debug version of the software.
            
            -D -> It is required an integer number after -D.
            It will generate new day component in the project

            -mf -> instead of ninja it will use unix Makefile for building
            """)
            exit()
        
                
        elif self.args.remove:
            os.system(self.removeEverything)
            if self.args.cmake:
                if self.args.debug:
                    self.directory = self.dirDebug
                self.runCmake(self.cmd, self.directory)
            if self.args.build:
                self.building()
                
        elif self.args.cmake:
            if self.args.debug:
                self.directory = self.dirDebug
            self.runCmake(self.cmd, self.directory)
            
            if self.args.build:
                self.building()
                
        elif self.args.build:
            self.building()
            
            
    def createComponent(self):
        if self.args.day:
            self.componentGenerator= CreateNewDay(self.args.day)
            self.componentGenerator.createDay()
            

