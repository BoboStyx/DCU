#!/usr/bin/env python3

s = input()


while s != "end":
   j = 0
   while j < len(s) and s[j:j + 4] != "City":
      j = j + 1
   if j < len(s) and s[j:j + 4] == "City" and s[0:j + 4] != "City":
      print(s[0:j + 4])
   s = input()
