#!/usr/bin/env python3

import sys

names = sys.stdin.readlines()

grade = 0
person = ""

i = 0
while i < len(names):
   name = names[i]
   j = len(name) - 1
   while j != 0 and name[j] != " ":
      j = j - 1
   if j != 0:
      grade = int(name[j + 1:])
      person = name[:j]
   if 40 <= grade:
      print(person)
   i = i + 1
