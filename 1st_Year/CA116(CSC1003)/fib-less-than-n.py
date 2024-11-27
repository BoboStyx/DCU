#!/usr/bin/env python3

n = int(input())

i = 0

current = 1
previous = 0
tmp = 1

print(0)

while (tmp) < n:
   print(tmp)
   tmp = current + previous
   previous = current
   current = tmp
