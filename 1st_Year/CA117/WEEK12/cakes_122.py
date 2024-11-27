#!/usr/bin/env python3

import sys

CakeList = sys.stdin.readlines()

for line in CakeList:
    cakes = line.split()
    prices = [int(price) for price in cakes]
    prices = sorted(prices, reverse=True)
    length = len(prices)
    i = 0
    total = 0
    for i in range(length // 3 + 1):
        total += sum(prices[:2])
        prices = prices[3:]
    print(total)
