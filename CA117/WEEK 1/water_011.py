#!/usr/bin/env python3

import sys

numbers = sys.stdin.readlines()

litres = int(numbers[0].strip())
full = 0
numbers = numbers[1].split()

j = 0
while j < len(numbers):
   number = int(numbers[j])
   litres -= number
   if litres >= 0:
      full += 1
   elif litres < 0:
      break
   j = j + 1

print(full)
