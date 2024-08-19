#!/usr/bin/env python3

curr = int(input())

prev = curr

while curr != 0:
   curr = int(input())
   if prev < curr and curr != 0:
      print("higher")
   elif prev > curr and curr != 0:
      print("lower")
   elif curr != 0:
      print("equal")
   prev = curr
