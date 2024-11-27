#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()
t = ""
reset = 0
capitals = {}

i = 0
while i < len(words):
   word = words[i]
   last = word[len(word) - 1]
   if reset == 0 and "a" <= word[0] <= "z":
      if word not in capitals:
         capitals[word] = word.capitalize()
      word = word.capitalize()
      reset = 1
   if last == "!" or last == "?" or last == ".":
      t = t + word + "\n"
      reset = 0
   else:
      t = t + word + " "
      reset = 1
   i = i + 1

print(t[:len(t) - 1])
