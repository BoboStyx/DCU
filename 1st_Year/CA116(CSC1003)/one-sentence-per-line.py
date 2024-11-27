#!/usr/bin/env python3

import sys

string = sys.stdin.read().split()
t = ""
m = 0
tmp = ""

i = 0
while string[i] != "end":
   if tmp != "":
      t = t + tmp + " "
      tmp = ""
   word = string[i]
   j = 0
   while j < len(word) and word[j] != ".":
      j = j + 1
   if j < len(word) and word[j] == ".":
      tmp = word[j + 1:]
      word = word[:j + 1]
   t = t + word + " "
   if j < len(word):
      print(t[:len(t) - 1])
      t = ""
   i = i + 1
