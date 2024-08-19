#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()
fruits = {}
a = "apple pear banana orange cherry".split()

i = 0
while i < len(a):
   fruits[a[i]] = True
   i = i + 1

i = 0
while i < len(words):
   word = words[i]
   if word in fruits:
      print(word)
   i = i + 1
