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
except (FileNotFoundError):
   print(f"This file {sys.argv[0]:s} {filename:s} could not be opened.")

if best != "":
   print(f"Best student: {best:s}")
   print(f"Best mark: {grade:d}")
