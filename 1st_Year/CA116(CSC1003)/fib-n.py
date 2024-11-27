#!/usr/bin/env python3

n = int(input())

i = 0
previous = 0
current = 1

if n > 0:
   print(0)
   print(1)

while i < (n - 2):
    tmp = current + previous
    print(tmp)
    previous = current
    current = tmp
    i = i + 1
