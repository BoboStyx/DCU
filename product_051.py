#!/usr/bin/env python3

import sys

numbers = sys.stdin.readline().strip()

multiplier = 1
for number in numbers:
    if number != "0":
        multiplier = int(number) * multiplier

product = multiplier
while product not in range(1, 10):
    multiplier = 1
    for number in str(product):
        if number != "0":
            multiplier = int(number) * multiplier
    product = multiplier

print(product)
