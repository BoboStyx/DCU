#!/usr/bin/env python3

import sys

for line in sys.stdin:
   words = line.split()
   print(sorted(words[0]) == sorted(words[1]))
