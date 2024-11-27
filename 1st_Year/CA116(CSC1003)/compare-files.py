#!/usr/bin/env python3

import sys

args = sys.argv[1:]

with open(args[0]) as f:
   s = f.read()

with open(args[1]) as f:
   t = f.read()

i = 0
while i < len(s) and i < len(t) and s[i] == t[i]:
   i = i + 1


if i <= len(s) and i <= len(t):
   same = s[:i]
   lines = same.split("\n")
   if len(lines) - 1 != 4:
      print((len(lines) - 1), len(lines[len(lines) - 1]))
