#!/usr/bin/env python3

import sys

original = sys.stdin.readline().strip()

translated = sys.stdin.readline().strip()

sticky = set()


for letter in original:
    if original.count(letter) < translated.count(letter):
        sticky.add(letter)

print(''.join(sorted(sticky)))
