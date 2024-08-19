#!/usr/bin/env python3

s = input()
n = int(s)

matching = True

i = 0
while i < len(s) // 2 and matching:
   p1 = i
   p2 = len(s) - i - 1

   d1 = n // 10 ** p1 % 10
   d2 = n // 10 ** p2 % 10

   matching = matching and d1 == d2
   i = i + 1

if matching:
   print("yes")
else:
   print("no")
