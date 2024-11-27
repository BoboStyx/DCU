#!/usr/bin/env python3

import sys

number = int(sys.argv[1])

current = 1
previous = 0
tmp = 1
even_total = 0

while current < number:
   if tmp % 2 == 0:
      even_total = even_total + current
   tmp = current + previous
   previous = current
   current = tmp

print(even_total)
