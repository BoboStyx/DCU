#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()
vowels = {"a","e","i","o","u"}
count = 0

for word in words:
    if count < word.lower().count("e"):
       count = word.lower().count("e")


def wordcomp(words):
    avs = sorted([word for word in words if vowels.issubset(word.lower())], key=len)
    print("Shortest word containing all vowels:", avs[0])
    print("Words ending in iary:", len([word for word in words if word[-4:].lower() == "iary"]))
    print("Words with most e's:", [word for word in words if "e" in word.lower() and word.lower().count("e") == count])

wordcomp(words)

