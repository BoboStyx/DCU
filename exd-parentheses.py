#!/usr/bin/env python3

import sys

s = sys.stdin.read().strip()

print(s)

i = 0
while i < len(s):
   j = i
   while j < len(s) and s[j] != "(":
      j = j + 1
      k = j
      while k < len(s) and s[k] != ")":
         k = k + 1
   print(s[j + 1:k])
   i = k + 1
