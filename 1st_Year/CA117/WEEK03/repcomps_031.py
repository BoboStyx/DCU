#!/usr/bin/env python3

import sys

numbers = sys.stdin.read().split()

def numcomps(n):
    for number in numbers:
        domain = list(range(1, int(number) + 1))
        print("Non-multiples of 3 replaced:", [0 if n % 3 else n for n in domain])

numcomps(numbers)
