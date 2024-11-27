#!/usr/bin/env python3

import sys

total = 0
args = sys.argv[1:]

j = 0
while j < len(args):
   with open(args[j]) as f:
      numbers = f.read().split()
   i = 0
   while i < len(numbers):
      number = int(numbers[i])
      total = total + number
      i = i + 1
   j = j + 1

print(total)
