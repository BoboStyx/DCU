#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
t = ""

i = 0
while lines[i] != "end\n":
   sentence = lines[i].split()
   sentence = sentence[5:]
   j = 0
   while j < len(sentence):
      t = t + sentence[j] + " "
      j = j + 1
   print(t[:len(t) - 1])
   t = ""
   i = i + 1
