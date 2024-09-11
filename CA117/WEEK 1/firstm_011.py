#!/usr/bin/env python3

import sys

lines = sys.stdin.read().split("\n")

i = 0
while i < len(lines) - 1:
   line = lines[i]
   line = line.replace("m", "M", 1)
   line = line.strip()
   print(line)
   i = i + 1
