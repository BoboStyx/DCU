#!/usr/bin/env python3

import sys

seen = set()
lines = []
for line in sys.stdin:
    line = line.strip().split()
    newS = ""
    for word in line:
        wordToCheck = None
        if word[-1] not in "abcdefghijklmnopqrstuvwxyz":
            wordToCheck = word[:-1]
        else:
            wordToCheck = word

        if wordToCheck.lower() in seen:
            newS += ". "
        else:
            seen.add(wordToCheck.lower())
            newS += word + " "
    lines.append(newS.rstrip())
 
print("\n".join(lines))
