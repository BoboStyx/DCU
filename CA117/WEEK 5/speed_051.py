#!/usr/bin/env python3

import sys

standard = sys.stdin.readline().split()
speed = 0

for lines in sys.stdin:
    line = lines.split()
    time = int(line[0]) - int(standard[0])
    distance = int(line[1]) - int(standard[1])
    standard[0], standard[1] = int(line[0]), int(line[1])
    if speed < distance // time:
        speed = distance // time

print(speed)
