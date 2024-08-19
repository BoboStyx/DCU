#!/usr/bin/env python3

s = input()
t = ""
caps = ""

i = 0
while i < len(s):
   t = s[i]
   if ord(s[i]) >= 97:
      t = chr(ord(s[i]) - 32)
   caps = caps + t
   i = i + 1

print(caps)
