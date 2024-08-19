#!/usr/bin/env python3

import sys

with open("a.txt") as f:
   words = f.read()
with open("b.txt") as f:
   words = words + f.read()

words = words.split()
dictionary = {}

i = 0
while i < len(words):
   word = words[i]
   if word not in dictionary:
      dictionary[word] = True
   i = i + 1

for word in dictionary:
   print(word)
