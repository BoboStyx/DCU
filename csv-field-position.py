#!/usr/bin/env python3

import sys
search = sys.argv[1]

s = input()
comma = 0
incr = 1

j = 0
while j < len(s) and s[j + 1:j + 1 + len(search)] != search:
   if s[j] == ",":
      incr = incr + 1
      comma = j + 1
   j = j + 1


if search != s[0:len(search)]:
   print(incr)
if search == s[0:len(search)]:
   print(0)
