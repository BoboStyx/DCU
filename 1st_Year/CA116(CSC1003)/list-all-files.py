#!/usr/bin/env python3

import os

files = [os.listdir(".")]
location = ["./"]

i = 0
while i < len(files):
   j = 0
   while j < len(files[i]):
      s = files[i][j]
      path = location[i] + s
      if os.path.isdir(path):
         files += [os.listdir(path)]
         location += [path + "/"]
      else:
         print(location[i] + files[i][j])
      j = j + 1
   i = i + 1
