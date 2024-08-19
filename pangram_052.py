#!/usr/bin/env python3

import sys

alphabet = "abcdefghijklmnopqrstuvwxyz"

for line in sys.stdin:
    line = line.strip()
    pangram = [letter for letter in alphabet if letter not in line.lower()]
    if pangram == []:
        print("pangram")
    else:
        print("missing", ''.join(pangram))
