#!/usr/bin/env python3

import sys

with open("characters.txt") as f:
   lines = f.readlines()

i = 0
while i < len(lines):
   line = lines[i]
   j = 0
   while j < len(line):
      ch = line[j]
      if ch != "\n":
         print(ch)
      elif ch == "\n":
         print("")
      j = j + 1
   i = i + 1
