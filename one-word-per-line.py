#!/usr/bin/env python3

import sys

lines = sys.stdin.read()
words = lines.split()
print(words)
print("\n".join(words))
