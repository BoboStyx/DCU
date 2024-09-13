#!/usr/bin/env python3

import sys

def isprimes(number):
    for i in range(2, int(number ** 0.5) + 1):
        if not number % i:
            return False
    return True

for number in numbers:
    number = int(number.strip()) + 1)
    print("Primes:" [number for number in numbers if prime(number)])
