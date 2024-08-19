#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
total = 0

i = 0
while lines[i] != "end\n":
   sentence = lines[i].split()
   total = total + int(sentence[2])
   i = i + 1

print(total)
