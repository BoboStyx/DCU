#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()


i = 0
while lines[i] != "end\n":
   sentence = lines[i].split()
   if int(sentence[2]) != 1:
      print(lines[i][0:len(lines[i]) - 1])
   i = i + 1
