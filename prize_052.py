#!/usr/bin/env python3

import sys

start = int(sys.stdin.readline().strip())

index = {1:'', 2:'', 3:''}

swaps = sys.stdin.readline().strip()
index[start] = "here"
for letter in swaps:
    if letter == "A":
        index[1], index[2] = index[2], index[1]
    elif letter == "B":
        index[2], index[3] = index[3], index[2]
    elif letter == "C":
        index[1], index[3] = index[3], index[1]

for word in index:
    if index[word] == "here":
        print(word)
