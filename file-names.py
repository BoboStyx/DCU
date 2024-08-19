#!/usr/bin/env python3

import sys
a = sys.stdin.readlines()

i = 0
while i < len(a):
   tokens = a[i].rstrip().split("/")
   print(tokens.pop())
   i = i + 1
