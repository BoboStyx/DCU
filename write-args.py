#!/usr/bin/env python3

import sys

args = sys.argv[2:]
file_name = (sys.argv[1])
s = ""

i = 0
while i < len(args):
   s = s + args[i] + "\n"
   i = i + 1

with open(file_name, "w") as f:
      f.write(s)
