#!/usr/bin/env python3

s = input()

t = ""

i = 0
while i < len(s):
   if s[i] <= "g" and "a" <= s[i]:
      t = s[i]
   if t == s[i]:
      i = len(s)
   i = i + 1

print(t)
