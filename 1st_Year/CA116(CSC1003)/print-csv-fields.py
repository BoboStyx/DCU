#!/usr/bin/env python3

t = ""
a = []

s = input()
while s != "end":
   a.append(s)
   s = input()

n = int(input())
m = 0

i = 0
while i < len(a):
   t = a[i]
   j = 0
   while j < len(t) and t[j] != ",":
      j = j + 1
   if j < len(t) and t[j] == "," and n == 0:
      print(t[:j])
   elif j < len(t) and t[j] == "," and n == 1:
      m = j + 1
      j = m
      while j < len(t) and t[j] != ",":
         j = j + 1
      if j < len(t) and t[j] == ",":
         print(t[m:j])
   elif j < len(t) and t[j] == "," and n == 2:
      while j < len(t) and t[j] != "N":
         j = j + 1
      if j < len(t) and t[j] == "N":
         print(t[j + 2:])
   i = i + 1
