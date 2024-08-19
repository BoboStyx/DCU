#!/usr/bin/env python3

s = input()
nospaces = ""

i = 0
while i < len(s):
   if ord(s[i]) != 32:
      nospaces = nospaces + s[i]
   i = i + 1

print(nospaces)
