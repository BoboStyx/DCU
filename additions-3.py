#!/usr/bin/env python3

total = 0

i = 0
while total != 1000:
   s = input()
   j = 0
   while j < len(s) and not("+" == s[j]):
      j = j + 1
   if j < len(s):
      total = int(s[:j]) + int(s[j + 1:])
      print(total)
   i = i + 1
