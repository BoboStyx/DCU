#!/usr/bin/env python3

import sys

translator = {}
file = sys.argv[1]

with open(file) as f:
    lines = f.readlines()

for line in lines:
    translation = line.split()
    translator[translation[0]] = translation[1]

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
        t += translator[numbering[number]] + " "
    t = t.strip()
    print(t)
