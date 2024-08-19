#!/usr/bin/env python3

negtotal = 0

total = 0


i = 0
while i < 5:
   n = int(input())
   if n < 0:
      negtotal = negtotal + n
   else:
      total = total + n
   i = i + 1

print(negtotal, total)
