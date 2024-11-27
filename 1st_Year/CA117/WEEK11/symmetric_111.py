#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()
dictionary = {}

for line in lines:
    name = line.strip()
    if len(name) not in dictionary:
        dictionary[len(name)] = []
    dictionary[len(name)].append(name)

for number in dictionary:
    print(dictionary[number][0])

pair = []
try:
    for number in dictionary:
        pair.append(dictionary[number][1])
except IndexError:
    pass

if len(lines) > 1:
    print(("\n".join(
    sorted(pair, key=len, reverse=True))).strip())
