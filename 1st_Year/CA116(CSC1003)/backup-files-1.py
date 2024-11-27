#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
   file = files[i]
   if file[len(file) - 3:] == "bak":
      os.unlink(file)
   i = i + 1
