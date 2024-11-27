#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
num = int(lines[len(lines) - 1])

i = 0
while lines[i] != "end\n":
   sentence = lines[i].split()
   if int(sentence[0]) == num:
     print(lines[i][0:len(lines[i]) - 1])
   i = i + 1
