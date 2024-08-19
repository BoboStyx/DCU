#!/usr/bin/env python3

import sys

translation = {}

english = "one two three four five six seven eight nine ten".split()
german = "eins zwei drei vier funf sechs sieben acht neun zehn".split()

i = 0
while i < len(english):
   translation[english[i]] = german[i]
   i = i + 1

words = sys.stdin.read().split()

i = 0
while i < len(words):
   print(translation[words[i]])
   i = i + 1
