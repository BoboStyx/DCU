#!/usr/bin/env python3

import sys
import string

seen = {}
words = sys.stdin.read().split()

for word in words:
    word = word.lower()
    t = ""
    for letter in word:
        if letter not in string.punctuation or letter == "'": 
            t += letter
    if t not in seen:
        seen[t] = 1
    elif t in seen:
        seen[t] += 1

storage = sorted(seen)

for word in storage:
    print(word, ":", seen[word])

