#!/usr/bin/env python3

import os

files = os.listdir(".")
line = ""

i = 0
while i < len(files):
   file = files[i]
   with open(file) as f:
      line = f.readline()
   if file[len(file) - 3:] == ".py" and line[:len(line) - 1] != "":
      print(file)
   elif line[:len(line) - 1] == "#!/usr/bin/env python3":
      print(file)
   i = i + 1
