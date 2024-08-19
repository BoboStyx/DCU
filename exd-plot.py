#!/usr/bin/env python3

import sys

numbers = sys.stdin.read().split()

greatest = 0
a = []
t = ""

i = 0
while i < len(numbers):
   number = int(numbers[i])
   if greatest < number:
      greatest = number
   i = i + 1

a =  [" "] * (greatest + 1)

i = 0
while i < len(numbers):
   number = int(numbers[i])
   a[number] = "*"
   i = i + 1

t = "|"
i = 0
while i < len(a):
   t = t + a[i]
   i = i + 1

t = t + "|"
print(t)
