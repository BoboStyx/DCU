#!/usr/bin/env python3

import sys


numbers = sorted([int(n) for n in sys.stdin.readline().split()])

letters = {"A":'', "B":'', "C":'', "D":'', "E":'', "F":''}

for letter in letters:
    letters[letter] = numbers[0]
    numbers = numbers[1:]

letter_line = sys.stdin.readline().strip()
t = ''

for letter in letter_line:
    t += str(letters[letter]) + " "

print(t.strip())
