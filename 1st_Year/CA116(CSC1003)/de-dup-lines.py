#!/usr/bin/env python3

a = []
s = input()
if s != "end":
   a.append(s)

while s != "end":
   i = 0
   while i < len(a) and s != a[len(a) - i - 1]:
      i = i + 1
   if i == len(a):
      a.append(s)
   s = input()

i = 0
while i < len(a):
   print(a[i])
   i = i + 1
