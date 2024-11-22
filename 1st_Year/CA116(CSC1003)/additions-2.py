#!/usr/bin/env python3

s = input()
total = 0

i = 0
while i < len(s):
   j = i
   while j < len(s) and not("+" == s[j]):
      j = j + 1
   if j < len(s) + 1:
      total = total + int(s[i:j])
   i = j + 1

print(total)
