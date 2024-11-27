#!/usr/bin/env python3

import sys

randomname = sys.stdin.read().split()

names = {}

with open("boys.txt") as f:
   boynames = f.read().split()

with open("girls.txt") as f:
   girlsnames = f.read().split()

i = 0
while i < len(boynames):
   name = boynames[i]
   if name not in names:
      names[name] = "boy"
   i = i + 1

i = 0
while i < len(girlsnames):
   name = girlsnames[i]
   if name not in names:
      names[name] = "girl"
   elif name in names:
      names[name] = "either"
   i = i + 1

i = 0
while i < len(randomname):
   person = randomname[i]
   if person in names:
      print(person, names[person])
   i = i + 1
