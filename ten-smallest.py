#!/usr/bin/env python3

n = 10
smallest = int(input())

i = 0
while i < n - 1:
   m = int(input())
   if smallest > m:
      smallest = m
   i = i + 1

print(smallest)
