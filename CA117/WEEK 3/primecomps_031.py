#!/usr/bin/env python3

import sys

def isprime(n):
    for i in range(2, (n // 2) + 1):
        if n % i == 0 and n != 2:
            return False
    return True

for lines in sys.stdin:
    number = int(lines.strip())
    print("Primes:", [n for n in list(range(2, number + 1)) if isprime(n)])
    
