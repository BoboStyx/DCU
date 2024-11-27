#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()

i = 0
while i < len(words):
   word = words[i]
   j = 0
   while j != 1:
      if "A" <= word[0] <= "Z":
         print(word)
      j = j + 1
   i = i + 1
