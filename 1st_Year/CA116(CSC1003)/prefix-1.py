#!/usr/bin/env python3

t = ""

i = 0
while i < len(a):
   t = a[i]
   if t[0:len(s)] == s:
      print(t)
   i = i + 1
