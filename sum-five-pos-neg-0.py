#!/usr/bin/env python3

negtotal = 0

total = 0

n = 1
while n != 0:
   n = int(input())
   if n < 0:
      negtotal = negtotal + n
   else:
      total = total + n


print(negtotal, total)
