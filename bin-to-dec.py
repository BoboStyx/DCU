#!/usr/bin/env python3

s = input()
total = 0

i = 0
while i < len(s):
   n = int(s[i])
   total = total + (n * (2 ** (len(s) - i - 1)))
   i = i + 1

print(total)
