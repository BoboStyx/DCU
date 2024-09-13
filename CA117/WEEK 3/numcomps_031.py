#!/usr/bin/env python3

import sys

numbers = sys.stdin.readlines()

def numcomps(num):
    for number in numbers:
        number = number.strip()
        domain = list(range(1, int(number) + 1))
        print("Multiples of 3:", [n for n in domain if not n % 3])
        print("Multiples of 3 squared:", [n * n for n in domain if not n % 3])
        print("Multiples of 4 doubled:", [n * 2 for n in domain if not n % 4])
        print("Multiples of 3 or 4:", [n for n in domain if not n % 3 or not n % 4])
        print("Multiples of 3 and 4:", [n for n in domain if not n % 3 and not n % 4])

numcomps(numbers)
