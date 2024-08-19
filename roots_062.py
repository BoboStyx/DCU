#!/usr/bin/env python3

import sys

equations = sys.stdin.readlines()

for equation in equations:
    x = []
    a, b, c = equation.split()
    a, b, c = int(a), int(b), int(c)
    if b ** 2 -4 * a * c < 0:
        print("None")
    else:
        x.append(str(((-b - (b ** 2 -4 * a * c) ** (1/2)) / (2 * a))))
        x.append(str(((-b + (b ** 2 -4 * a * c) ** (1/2)) / (2 * a))))
        x[0] = str(round(float(x[0]), 1))
        x[1] = str(round(float(x[1]), 1))
        print(', '.join(x))

