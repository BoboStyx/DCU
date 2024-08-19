#!/usr/bin/env python3

import sys

x, y, n = sys.stdin.readline().split()
x, y, n = int(x), int(y), int(n)

def fizzbuzz(x, y, n):
    for i in range(1, n + 1):
        if i % x == 0 and i % y == 0:
            print("fizzbuzz")
        elif i % x == 0:
            print("fizz")
        elif i % y == 0:
            print("buzz")
        else:
            print(i)

fizzbuzz(x, y, n)
