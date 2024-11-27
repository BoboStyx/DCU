#!/usr/bin/env python3

import sys


numbering = {1: "one",
        2: "two",
        3: "three",
        4: "four",
        5: "five",
        6: "six",
        7: "seven",
        8: "eight",
        9: "nine",
        10: "ten",
        0: "zero"}

lines = sys.stdin.readlines()


for line in lines:
    t = ""
    line = line.split()
    for number in line:
        number = int(number)
        t += numbering[number] + " "
    t = t.strip()
    print(t)
