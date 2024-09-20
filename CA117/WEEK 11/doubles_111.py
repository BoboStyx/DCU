#!/usr/bin/env python3

import sys

vowels = ["a", "e", "i", "o", "u"]
doubled = {}

def doubles(word):
    i = 0
    doubled[word] = 0
    while i < len(word) - 1:
        if word[i] in vowels:
            if word[i] == word[i + 1]:
                doubled[word] += 1
        i += 1

for lines in sys.stdin:
    line = lines.strip()
    doubles(line)

greatest = max(doubled.values())

for word in doubled:
    if doubled[word] == greatest:
        print(word)
        break
