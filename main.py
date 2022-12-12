#!/usr/bin/python
import sys
import adventUtil.builder as builder


if __name__ == "__main__":

    buildGenerator = builder.Builder(len(sys.argv))
    buildGenerator.run()
    buildGenerator.createComponent()
    