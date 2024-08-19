#!/usr/bin/env python3

total = 0

n = 1
while n != 0:
   n = int(input())
   if n < 0:
      n = n * -1
   total = total + n

print(total)
