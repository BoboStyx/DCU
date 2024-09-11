#!/usr/bin/env python3

import sys
for lines in sys.stdin:
   line = lines.strip()
   if len(line) % 2 == 0:
      print("No middle character!")
   else:
      print(line[len(line) // 2])
