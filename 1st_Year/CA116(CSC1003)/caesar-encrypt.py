#!/usr/bin/env python3

import sys

s = sys.stdin.read().strip()

n = 13
lower = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

lower_rev = lower[n:] + lower[:n]
upper_rev = upper[n:] + upper[:n]

d = {}

i = 0
while i < len(lower):
   d[lower[i]] = lower_rev[i]
   d[upper[i]] = upper_rev[i]
   i = i + 1

t = []

i = 0
while i < len(s):
   if s[i] in d:
      t.append(d[s[i]])
   else:
      t.append(s[i])
   i = i + 1

print("".join(t))
