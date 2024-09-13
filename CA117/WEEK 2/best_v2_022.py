#!/usr/bin/env python3

import sys

filename = sys.argv[1]
grade = -1
try:
   with open(filename) as f:
      lines = f.readlines()
   for line in lines:
      line = line.strip()
      line = line.split(" ", 1)
      if grade < int(line[0]):
         best = line[1]
         grade = int(line[0])
   if best != "":
      print(f"Best student: {best:s}")
      print(f"Best mark: {grade:d}")
except (ValueError):
   print(f"Invalid mark {line[0]} encountered. Exiting.")
