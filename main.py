#!/usr/bin/python

import sys
import adventUtil.createNewDay as creator


if __name__ == "__main__":

    generator = creator.CreateNewDay(sys.argv[1])
    generator.createDay()
    pass