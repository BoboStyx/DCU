#!/usr/bin/env python3

import sys

link = "".join(sys.argv[1].split("//"))
item = ["scheme:", "host:", "port:", "path:", "query-string:", "fragment-id:"]
id = [":", "#", "/", "?"]

i, j, prev, offset = 0, 0, 0, 0
while i <= len(link):
   b = i == len(link)
   if b or link[i] == id[0] or link[i] == id[1] or link[i] == id[2 + offset]:
      if i < len(link) and link[i] == "/":
         offset = 1
      print(item[j], link[prev:i])
      prev = i
      if i != 0 and i < len(link) and link[i] != "/":
         prev += 1
      j += 1
      a, b = len(link.split(":")), len(link.split("?"))
      if (j == 2 and a == 2) or (j == 4 and b == 1):
         j += 1
   i += 1
