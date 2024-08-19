#!/usr/bin/env python3

a = []
a2 = []

s = input()
while s != "end":
   a.append(s)
   s = input()

t = input()
while t != "end":
   a2.append(t)
   t = input()

i = 0
j = 0
while i < len(a) and j < len(a2):
   if int(a[i]) < int(a2[j]):
      print(a[i])
      i = i + 1
   elif int(a[i]) == int(a2[j]):
      print(a[i])
      j = j + 1
   else:
      print(a2[j])
      j = j + 1

while i < len(a):
   print(a[i])
   i = i + 1

while j < len(a2):
   print(a2[j])
   j = j + 1
