#!/usr/bin/env python3

s = input()

i = 0
while i + 1 < len(s) and not(s[i] == s[i + 1]):
   i = i + 1

if i + 1 < len(s):
   print(s[i:i + 2])
