#!/usr/bin/env python3

s = input()
reverse = ""

i = 0
while i < len(s):
   t = s[len(s) - i - 1]
   reverse = reverse + t
   i = i + 1

print(reverse)
