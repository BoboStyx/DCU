#!/usr/bin/env python3

import sys

with open("a.txt") as f:
   worda = f.read().split()
with open("b.txt") as f:
   wordb = f.read().split()

dictionary = {}

i = 0
while i < len(worda):
   word = worda[i]
   if word not in dictionary:
      dictionary[word] = "a"
   i = i + 1

i = 0
while i < len(wordb):
   word = wordb[i]
   if word in dictionary:
      dictionary[word] = "ab"
   else:
      dictionary[word] = "b"
   i = i + 1

j = 0
while j < len(worda) and dictionary[worda[j]] != "ab":
   j = j + 1

if j < len(worda):
   print("intersecting")
else:
   print("disjoint")
