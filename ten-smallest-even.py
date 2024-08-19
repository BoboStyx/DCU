#!/usr/bin/env python3

n = 10
smalleven = int(input())

i = 0
while i < n - 1:
   m = int(input())
   if smalleven > m and m % 2 == 0:
      smalleven = m
   i = i + 1

print(smalleven)
