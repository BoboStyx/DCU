#!/usr/bin/env python3

import sys

for line in sys.stdin:
    s = ''
    line = line.strip()

    currLetter = line[0]
    currNum = 1
    for i, letter in enumerate(line[1:]):
        if letter == currLetter:
            currNum += 1
        else:
            s += str(currNum) + currLetter
            currLetter = letter
            currNum = 1

    s += str(currNum) + currLetter
    print(s)

