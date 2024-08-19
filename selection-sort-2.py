#!/usr/bin/env python3

a = []
tmp = ""

s = input()
while s != "end":
   a.append(s)
   s = input()

i = int(input())
p = i
j = p + 1
while j < len(a):
   if int(a[j]) < int(a[p]):
      p = j
   j = j + 1

print(p)
