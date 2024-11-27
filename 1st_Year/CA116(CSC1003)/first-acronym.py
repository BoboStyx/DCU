#!/usr/bin/env python3

s = input()

i = 0
while i < len(s) and not("A" <= s[i] and s[i] <= "Z"):
   i = i + 1
   j = i
   while j < len(s) and ("A" <= s[j] <= "Z"):
      j = j + 1

if i == 0:
   print(s[i:], i)
elif i < len(s):
   print(s[i:j], i)
