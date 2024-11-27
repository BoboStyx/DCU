#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()

animals = {}

i = 0
while i < len(words):
   word = words[i]
   if word not in animals:
      animals[word] = 1
   else:
      animals[word] = animals[word] + 1
   i = i + 1

count = 0
i = 0
while count != 1 and i < len(words):
   if animals[words[i]] == 2:
      print("snap:", words[i])
      count = count + 1
   i = i + 1
