#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()

def wordcomps(words):
    print("Words containing 17 letters:", [word for word in words if len(word) == 17])
    print("Words containing 18+ letters:", [word for word in words if len(word) > 17])
    print("Words with 4 a's:", [word for word in words if word.lower().count("a") == 4])
    print("Words with 2+ q's:", [word for word in words if word.lower().count("q") == 2])
    print("Words containing cie:", [word for word in words if "cie" in word.lower()])
    print("Anagrams of angle:", [word for word in words if "a" in word.lower() and "n" in word.lower() and "g" in word.lower() and "l" in word.lower() and "e" in word.lower() and len(word) == 5 and word.lower() != "angle"])

wordcomps(words)
