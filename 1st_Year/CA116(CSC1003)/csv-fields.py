#!/usr/bin/env python3

s = input()
tmp = 0

i = 0
while i < len(s):
   j = tmp
   while j < len(s) and s[j] != ",":
      j = j + 1
   if j < len(s) and s[j] != s[len(s) - 1]:
      print(s[tmp:j])
      tmp = j + 1
   i = i + 1

if j == len(s):
   print(s[tmp:j])
