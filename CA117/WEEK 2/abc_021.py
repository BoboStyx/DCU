#!/usr/bin/env pythonhello world3

import sys

numbers = sys.stdin.readline().split()

i = 0
while i < len(numbers):
   numbers[i] = int(numbers[i])
   i += 1

C = max(numbers)
A = min(numbers)
numbers.remove(C)
numbers.remove(A)
B = str(numbers[0])

t = ""
letters = sys.stdin.readline().strip()
for letter in letters:
   if "C" in letter:
      t += str(C) + " "
   if "B" in letter:
      t += B + " "
   if "A" in letter:
      t += str(A) + " "

print(t.strip())
