#!/usr/bin/env python3

import sys

filename = sys.argv[1]
grade = -1
best = []
t = ""

with open(filename) as f:
   lines = f.readlines()
for line in lines:
   line = line.strip()
   line = line.split(" ", 1)
   if grade < int(line[0]):
      grade = int(line[0])

for line in lines:
   line = line.strip()
   line = line.split(" ", 1)
   if grade == int(line[0]):
      best.append(line[1])


i = 0
while i < len(best):
   t += best[i] + ", "
   i += 1

if best != "":
   print(f"Best student(s): {t.rsplit(',', 1)[0]:s}")
   print(f"Best mark: {grade:d}")
