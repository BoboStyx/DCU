#!/usr/bin/env python3

import sys

vowels = ["a", "e", "i", "o", "u"]
for line in sys.stdin:
    sentence = line.strip()
    i = 0
    while i < len(sentence):
        if sentence[i - 1] in vowels:
            if sentence[i] == "p" and sentence[i + 1] == sentence[i - 1]:
                sentence = sentence[:i] + sentence[i + 2:]
        i += 1
    print(sentence)

