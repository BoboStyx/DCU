#!/usr/bin/env python3

a = []
s = input()

while s != "end":
   a.append(s)
   s = input()

i = 0
while i < len(a):
   print(a[len(a) - 1 - i])
   i = i + 1