#!/usr/bin/env python3

import os
files = os.listdir(".")         # Line A.

i = 0
while i < len(files):
   file = files[i]
   if file[len(file) - 3:] == ".py":       # Line B.
      print(file)
   i = i + 1
