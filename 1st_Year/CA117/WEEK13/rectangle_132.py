#!/usr/bin/env python3

import sys

points = sys.stdin.readlines()

x_seen = {}
y_seen = {}

for point in points:
    x, y = point.split()
    if x not in x_seen:
        x_seen[x] = 1
    elif x in x_seen:
        x_seen[x] += 1
    if y not in y_seen:
        y_seen[y] = 1
    elif y in y_seen:
        y_seen[y] += 1

newpoint = ["", ""]
for point in x_seen:
    if x_seen[point] != 2:
        newpoint[0] = str(point)

for point in y_seen:
    if y_seen[point] != 2:
        newpoint[1] = str(point)

print(" ".join(newpoint))
