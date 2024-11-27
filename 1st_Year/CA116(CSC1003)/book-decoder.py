#!/usr/bin/env python3

import sys

coded = sys.stdin.read().split("\n")
t = ""
coded = coded[:len(coded) - 1]

i = 0
while i < len(coded):
   code = coded[i].split()
   page = code[0]
   line = int(code[1])
   ch = int(code[2])
   with open("page-" + page + ".txt") as f:
      content = f.readlines()
   j = 0
   while j < len(content[line]) and j != ch:
      j = j + 1
   t = t + content[line][j]
   i = i + 1

print(t[:len(t) - 1])
