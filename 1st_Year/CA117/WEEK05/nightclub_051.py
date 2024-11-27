#!/usr/bin/env python3

import sys

capacity = int(sys.stdin.readline().strip())
denied = 0

for line in sys.stdin:
    line = line.split()
    nature = line[0]
    number = int(line[1])
    if nature == "enter":
        if capacity >= number:
            capacity -= number
        elif capacity < number:
            denied += 1
    elif nature == "leave":
        capacity += number

print(denied)
