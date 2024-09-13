#!/usr/bin/evn python3

import sys

words = sys.stdin.read().split()
unique = []

for word in words:
   word = word.strip()
   word = word.lower()
   t = ""
   for letter in word:
      if letter.isalnum():
         t = t + letter
   if t not in unique:
      unique.append(t)

print(len(unique) - 1)
