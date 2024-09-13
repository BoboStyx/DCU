#!/usr/bin/env python3

import sys

poem = sys.stdin.readlines()

greatest = 0

i = 0
while i < len(poem):
   line = poem[i].strip()
   if greatest < len(line):
      greatest = len(line)
   i += 1

i = 0
while i < len(poem):
   line = poem[i].strip()
   print(f'{line: ^{greatest}}')
   i += 1
