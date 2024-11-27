#!/usr/bin/env python3

import sys

filename = sys.argv[1]
grade = -1

with open(filename) as f:
      lines = f.readlines()
for line in lines:
   try:
      line = line.strip()
      line = line.split(" ", 1)
      if grade < int(line[0]):
         best = line[1]
         grade = int(line[0])
   except (ValueError):
      print(f"Invalid mark {line[0]} encountered. Skipping.")

if best != "":
   print(f"Best student: {best:s}")
   print(f"Best mark: {grade:d}")
