#!/usr/bin/env python3

import sys
for lines in sys.stdin:
   line = lines.split()
   word1 = line[0].lower()
   word2 = line[1].lower()
   i = 0
   while i < len(word2) and word2[i:i + len(word1)] != word1:
      i = i + 1
   if i < len(word2):
      print("True")
   else:
      print("False")
