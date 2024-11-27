#!/usr/bin/env python3

a = []


s = input()
while s != "end":
   a.append(s)
   s = input()

i = 0
while i < len(a):
   j = 0
   increment = 0
   while j < len(a):
      if int(a[j]) == i:
         increment = increment + 1
      j = j + 1
   if i < 10:
      print(str(i) + " " + "*" * increment)
   i = i + 1

i = 0
while a == [] and i < 10:
   print(str(i) + " ")
   i = i + 1
