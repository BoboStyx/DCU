#!/usr/bin/env python3

s = input()
a = []

while s != "end":
   a.append(s)
   s = input()

n = int(input())

i = 0
while i < len(a):
   a[i] = int(a[i]) + n
   print(a[i])
   i = i + 1
