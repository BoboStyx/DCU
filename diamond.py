#!/usr/bin/env python3

import sys

args = sys.argv[1:]

i = 0
n = int(args[0])

m = 1
posincr = 1
negincr = n // 2

i = 0
while i < n:
   if i < n // 2:
      print(" " * negincr + "*" * m)
      m = m + 2
      negincr = negincr - 1
   elif i == n // 2:
      print("*" * n)
   else:
      m = m - 2
      print(" " * posincr + "*" * m)
      posincr = posincr + 1
   i = i + 1
