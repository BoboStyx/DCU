#!/usr/bin/env python3

import os

with open("start.txt") as f:
   hint = f.readline()
hint = hint[:len(hint) - 1]

while os.path.isfile(hint):
   with open(hint) as f:
      hint = f.readline()
   hint = hint[:len(hint) - 1]

print(hint)
