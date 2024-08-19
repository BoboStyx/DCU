#!/usr/bin/env python3

n = int(input())

i = 0
while i < n:
   if i != n // 2:
      print(" " * (n // 2) + "*")
   else:
      print("*" * n)
   i = i + 1
