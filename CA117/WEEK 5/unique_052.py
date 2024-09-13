#!/usr/bin/env python3

import sys

def unique(numbers):
    unique = [int(n) for n in numbers if numbers.count(n) == 1]
    return max(unique, default="none")

for line in sys.stdin:
    numbers = line.strip()
    print(unique(numbers))
