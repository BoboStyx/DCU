#!/usr/bin/env python3

import sys

total = 0

i = 0
args = sys.argv[1:]
while i < len(args):
   total = total + int(args[i])
   i = i + 1

print(total)