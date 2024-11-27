#!/usr/bin/env python3

import sys

position = int(sys.argv[1])

n = 0
s = input()
m = 0

j = 0
while j < len(s):
   if s[j] == "," and m < position:
      n = j
      m = m + 1
   if m == position and s[j] == ",":
      i = n + 1
      m = position + 1
      while i < len(s) and s[i] != ",":
         i = i + 1
   j = j + 1

if n != 0:
   print(s[n + 1:i])
else:
   print(s[n:i])
