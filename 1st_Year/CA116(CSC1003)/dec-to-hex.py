#!/usr/bin/env python3

n = int(input())
base = 16
digits = "0123456789abcdef"
t = ""

i = 0
while n != 0:
   t = digits[n % base] + t
   n = n // base

print(t)
