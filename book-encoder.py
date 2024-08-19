#!/usr/bin/env python3

import sys

n = 10
book = []
used = {}
intro = ["page-", "input-"]

i = 0
while i < n:
    with open(intro[0] + str(i) + ".txt") as f:
        book.append(f.readlines())
    i += 1

input = sys.stdin.read()

i = 0
while i < len(input):
    c = input[i]
    if c in used:
        used[c] += 1
    else:
        used[c] = 0
    pos = []
    n = used[c]

    j = 0
    while n >= (len("".join(book[j]).split(c)) - 1):
        n -= (len("".join(book[j]).split(c)) - 1)
        j += 1
    pos.append(str(j))
    j = 0
    while n >= (len(book[int(pos[0])][j].split(c)) - 1):
        n -= (len(book[int(pos[0])][j].split(c)) - 1)
        j += 1
    pos.append(str(j))
    length = len(c.join(book[int(pos[0])][int(pos[1])].split(c)[:n + 1]))
    pos.append(str(length))
    print(" ".join(pos))
    i += 1
