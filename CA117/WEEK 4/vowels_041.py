#!/usr/bin/env python3

import sys


greatest = 0
vowels = {"a": 0, "e": 0, "i": 0, "o": 0, "u": 0}

lines = [line.strip() for line in sys.stdin]

for line in lines:
    line = line.lower()
    for c in line:
        if c in vowels:
            vowels[c] += 1
    
for vowel in vowels:
    if greatest < len(str(vowels[vowel])):
        greatest = len(str(vowels[vowel]))


for vowel in sorted(vowels.items(), key=lambda x:x[1], reverse=True):
    print(f'{vowel[0]} : {vowel[1]:>{greatest}}')
