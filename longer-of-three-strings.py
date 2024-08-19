#!/usr/bin/env python3

s = input()
t = input()
d = input()

if len(d) < len(s) and len(t) < len(s):
   print(s)
elif len(t) < len(d) and len(s) < len(d):
   print(d)
elif len(s) < len(t) and len(d) < len(t):
   print(t)
