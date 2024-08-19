#!/usr/bin/env python3

import os
files = os.listdir(".")         # Line A.
line = ""

i = 0
while i < len(files):
   file = files[i]
   if file[len(file) - 3:] == ".py":       # Line B.
      with open(file) as f:
         line = f.readline()
      if line[:len(line) - 1] == "#!/usr/bin/env python3":
         print(file)
   i = i + 1
