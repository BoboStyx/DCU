#!/usr/bin/env python3

n = int(input())
m = int(input())
i = 0
n = n - 1
print(m)

while i < n:
   if (m % 2) != 0:
      m = 3 * m + 1
      print(m)
   else:
      m = m // 2
      print(m)
   i = i + 1
