#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()
t = ""

i = 0
while i < len(words):
   word = words[i]
   last = word[len(word) - 1]
   if last == "!" or last == "?" or last == ".":
      t = t + word + "\n"
   else:
      t = t + word + " "
   i = i + 1

print(t[:len(t) - 1])
