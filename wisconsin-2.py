#!/usr/bin/env python3

s = input()
total = 0

while s != "end":
   j = 0
   while j < len(s) and s[j:j + 2] != "WI":
      j = j + 1
      if j < len(s) and s[j:j + 2] == "WI":
         total = total + 1
   s = input()

print(total)
