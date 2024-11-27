#!/usr/bin/env python3

s = input()
sum = 0

i = 0
while i < len(s):
   sum = int(s[i]) + sum
   i = i + 1

print(sum)
