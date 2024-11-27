#!/usr/bin/env python3

import sys

texts = sys.stdin.read().split()

for text in texts:
    e_s = text.count("e")
    print("h" + "e" * (e_s * 2) + "y")
