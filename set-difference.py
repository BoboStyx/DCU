#!/usr/bin/env python3

import sys

with open("a.txt") as f:
   worda = f.read()
with open("b.txt") as f:
   wordb = f.read()

worda = worda.split()
wordb = wordb.split()
dictionary = {}

i = 0
while i < len(worda):
   word = worda[i]
   if word not in dictionary:
      dictionary[word] = 0
   i = i + 1

i = 0
while i < len(wordb):
   word = wordb[i]
   if word in dictionary:
      dictionary[word] = dictionary[word] + 1
   i = i + 1

for word in dictionary:
   if dictionary[word] != 1:
      print(word)
