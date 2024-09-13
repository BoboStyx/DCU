#!/usr/bin/env python3

import sys


def binsearch(search, words):
    low = 0
    high = len(words) - 1
    while low <= high:
        mid = (low + high) // 2
        if words[mid].lower() < search:
            low = mid + 1
        elif words[mid].lower() > search:
            high = mid - 1
        else:
            return True
    return False

words = [word.strip() for word in sys.stdin if len(word) >= 6]

print([word for word in words if binsearch(word[::-1].lower(), words)])
