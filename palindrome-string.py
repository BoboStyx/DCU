#!/usr/bin/env python3

s = input()
t = True

i = 0
while i < len(s):
   if not(s[i] == s[len(s) - 1 - i]):
      t = False
   i = i + 1

if t:
   print("palindrome")
