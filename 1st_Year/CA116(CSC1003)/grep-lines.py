#!/usr/bin/env python3

import sys

args = sys.argv[1:]
a = []

s = input()
while s != "end":
   i = 0
   while i < len(s) and s[i:i + len(args[0])] != args[0]:
      i = i + 1
   if i < len(s) and s[i:i + len(args[0])] == args[0]:
      a.append(s)
   s = input()

i = 0
while i < len(a):
   print(a[i])
   i = i + 1
