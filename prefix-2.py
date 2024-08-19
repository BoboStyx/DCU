#!/usr/bin/env python3

t = ""

i = 0
while i < len(a) and ((a[i])[0:len(s)]) != s:
   i = i + 1

if i < len(a):
   print(a[i])
