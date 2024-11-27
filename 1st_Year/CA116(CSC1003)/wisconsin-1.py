#!/usr/bin/env python3

s = input()

while s != "end":
   j = 0
   while j < len(s) and s[j:j + 2] != "WI":
      j = j + 1
      if j < len(s) and s[j:j + 2] == "WI":
         print(s[:j - 1])
   s = input()
