#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
t = ""

i = 0
while lines[i] != "end\n":
   sentence = lines[i].split()
   hours = int(sentence[2])
   sentence[2] = str(int(sentence[1]) + (hours - 1)) + ":50"
   if 10 <= int(sentence[1]):
      sentence[1] = sentence[1] + ":00"
   else:
      sentence[1] = sentence[1][1:] + ":00"
   j = 0
   while j < len(sentence):
      t = t + sentence[j] + " "
      j = j + 1
   print(t[:len(t) - 1])
   t = ""
   i = i + 1
