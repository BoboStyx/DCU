#!/usr/bin/env python3

import sys
for lines in sys.stdin:
   lines = lines.strip()
   if lines[1:-1] != "":
      print(lines[1:-1])
