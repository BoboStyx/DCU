#!/usr/bin/env python3

import os

files = os.listdir(".")

i = 0
while i < len(files):
   file = files[i]
   if file[len(file) - 3:] != "bak" and os.path.isfile(file):
      with open(file) as f:
         data = f.read()
      with open(file + ".bak", "w") as f:
         f.write(data)
   i = i + 1
