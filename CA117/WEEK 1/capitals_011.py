#!/usr/bin/env python3

import sys
for lines in sys.stdin:
   line = lines.strip()
   line = line.capitalize()
   line = line[:len(line) - 1] + line[len(line) - 1].capitalize()
   print(line)
