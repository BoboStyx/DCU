#!/usr/bin/env python3

s = input()
n = 0

i = 0
while i < len(s):
   if ("A" <= s[i] and s[i] <= "Z"):
      n = n + 1
   i = i + 1

print(n)
