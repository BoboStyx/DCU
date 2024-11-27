#!/usr/bin/env python3

curr = int(input())

prev = curr

i = 0
while i < 5:
   curr = int(input())
   if prev < curr:
      print("higher")
   elif prev > curr and :
      print("lower")
   else:
      print("equal")
   prev = curr
   i = i + 1
