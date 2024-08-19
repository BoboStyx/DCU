#!/usr/bin/env python3

n = 10
largest = int(input())

i = 0
while i < n - 1:
   m = int(input())
   if largest < m:
      largest = m
   i = i + 1

print(largest)
