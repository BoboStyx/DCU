#!/usr/bin/env python3

a = []

i = 0
s = input()
while s != "end":
   count = 0
   a.append([i, count])

   if int(s) <= i:
      (a[int(s)][1]) += 1
      s = input()
   i += 1

i = 0
while i < len(a):
   if 0 < (a[i][1]):
      print(str(a[i][0]))
      a[i][1] -= 1
      i -= 1
   i += 1
