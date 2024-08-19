#!/usr/bin/env python3

a = int(input())
b = int(input())
tmp = 0

while b != 0:
   tmp = a
   a = b
   b = tmp - b * (tmp // b)

print(a)
