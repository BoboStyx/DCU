#!/usr/bin/env python3

import sys

search = sys.argv[1]
search = search.split("=")
fieldname = search[0]
value = search[1]

i = 0
pos = 0
header = input()
while i < len(header) and header[i:len(fieldname) + i] != fieldname:
   if header[i] == ",":
      pos = pos + 1
   i = i + 1

s = input()
while s != "end":
   p = 0
   i = 0
   while i < len(s):
      if s[i] == ",":
         p = p + 1
      if s[i:i + len(value)] == value and p == pos:
         print(s)
      i = i + 1
   s = input()
