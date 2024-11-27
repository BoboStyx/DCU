#!/usr/bin/env python3

a = int(input())
b = int(input())
c = int(input())

if (c < a + b) and (b < c + a) and (a < c + b):
   print("yes")

else:
   print("no")
