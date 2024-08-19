#!/usr/bin/env python3

with open("letters.txt") as f:
   t = f.read()

with open("digits.txt") as f:
   s = f.read()

with open("letters.txt", "w") as f:
   f.write(s)

with open("digits.txt", "w") as f:
   f.write(t)
