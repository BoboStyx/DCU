#!/usr/bin/env python3

import sys

temperatures = [int(n) for n in sys.stdin.read().split()]
hottest = max(temperatures) + 1
i = 0
while i < len(temperatures) - 2:
    if temperatures[i] < hottest and temperatures[i + 2] < hottest:
        hottest = temperatures[i + 2] if temperatures[i] < temperatures[i + 2] else temperatures[i]
        day = i + 1
    i += 1

print(day, hottest)
