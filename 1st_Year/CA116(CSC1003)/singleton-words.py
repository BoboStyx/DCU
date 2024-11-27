#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()
dictionary = {}


i = 0
while i < len(words):
   word = words[i]
   if word not in dictionary:
      dictionary[word] = 1
   elif word in dictionary:
      dictionary[word] = 2
   i = i + 1

for word in dictionary:
   if dictionary[word] == 1:
      print(word)
