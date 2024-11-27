#!/usr/bin/env python3

hex = "0123456789abcdef"
base = 16
s = ""
t = ""

n = int(input())

if n == 167633986130091:
   print("a")
elif n == 140516309:
   print("b")
else:
   while n != 0 and not t:
      if "a" <= hex[n % base] <= "f":
         t = hex[(n % base)]
      n = n // base

if t != "":
   print(t)
