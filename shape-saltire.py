#!/usr/bin/env python3

n = int(input())
m = n
m2 = -1

i = 0
while i < n:
   if i < n // 2:
      print(" " * i + "*" + " " * (m - 2) + "*")
   elif i == n // 2:
      print(" " * (n // 2) + "*")
   else:
      m2 = m2 + 2
      print(" " * (n - i - 1) + "*" + " " * (m2) + "*")
   m = m - 2
   i = i + 1
