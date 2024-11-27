#!/usr/bin/env python3

import sys

number = int(sys.argv[1])
a = []
a.append(number)

i = 0
while i < 9:
   if number % 2 == 0:
      number = number // 2
      a.append(number)
   elif number % 2 == 1:
      number = number * 3 + 1
      a.append(number)
   i = i + 1

i = len(a) - 1
while 0 <= i:
   print(a[i])
   i -= 1
