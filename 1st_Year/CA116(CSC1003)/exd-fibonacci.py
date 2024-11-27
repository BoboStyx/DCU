#!/usr/bin/env python3

import sys

number = int(sys.stdin.read().strip())

tmp = 1
current = 1
previous = 0

while current < number:
   tmp = current + previous
   previous = current
   current = tmp

if current == number:
   print("yes")

else:
   print("no")
