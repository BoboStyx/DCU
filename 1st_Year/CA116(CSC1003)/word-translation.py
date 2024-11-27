#!/usr/bin/env python3

import sys

numbers = sys.stdin.read().split()

with open("translation.txt") as f:
   lines = f.readlines()

translation = {}

i = 0
while i < len(lines):
   word = lines[i].split()
   translation[word[0]] = word[1]
   i = i + 1

i = 0
while i < len(numbers):
   print(translation[numbers[i]])
   i = i + 1
