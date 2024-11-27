#!/usr/bin/env python3

import sys

file = sys.argv[1]
words = sys.stdin.read().strip()

with open(file) as f:
    censors = f.read().split()

for censor in censors:
    words = words.replace(censor, "@" * len(censor))


print(words)
