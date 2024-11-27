#!/usr/bin/env python3

total = 0
n = 10
tmp = 0
store = 0

i = 0
while i < n:
   m = int(input())
   tmp = m * (10 ** (i))
   store = tmp + store
   i = i + 1

i = 0
while i < n:
   total = (store // (10 ** (9 - i))) % 10
   i = i + 1
   print(total)
