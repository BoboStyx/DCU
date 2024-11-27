#!/usr/bin/env python3

def collatz(n):
    if n == 1:
        print(n)
        return 1
    print(n)
    if n % 2 == 0:
        n = n // 2
    elif n % 2 == 1:
        n = n * 3 + 1
    return collatz(n)
