#!/usr/bin/env python3

import sys

size = 20

row = [" "] * size
grid = []

i = 0
while i < size:
   grid.append(row[:])
   i = i + 1

pairs = sys.stdin.read().split()

i = 0
while i < len(pairs) // 2:
   x = int(pairs[i * 2])
   y = int(pairs[i * 2 + 1])
   grid[y][x] = "*"
   i = i + 1

print(" " + size * "-")

i = 0
while i < len(grid):
   print("|" + "".join(grid[size - i - 1]) + "|")
   i = i + 1

print(" " + size * "-")
