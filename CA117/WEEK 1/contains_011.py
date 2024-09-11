#!/usr/bin/env python3

import sys

for line in sys.stdin:
   t = True
   line = line.split()
   word1 = line[0].lower()
   word2 = line[1].lower()
   for letter in word1:
      if letter in word2:
         word2 = word2.replace(letter, "-", 1)
      else:
         print("False")
         t = False
         break
   if t == True:
      print("True")
