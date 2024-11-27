#!/usr/bin/env python3

import sys

america_dob = []
t = ""

with open("irish-dobs.txt") as f:
   dobs = f.read().split()

with open("irish-dobs.txt") as f:
   help = f.readlines()

a = []

i = 0
while i < len(dobs):
   dob = dobs[i]
   j = 0
   while j != 1:
      dob = dob.split("/")
      if 1 < len(dob):
         tmp = dob[0]
         dob[0] = dob[1]
         dob[1] = tmp
         dob = "/".join(dob)
         america_dob.append(dob)
      j = 1
   i = i + 1

i = 0
while i < len(america_dob):
   sentence = help[i].split()
   sentence[0] = america_dob[i]
   j = 0
   while j < len(sentence):
      t = t + sentence[j] + " "
      j = j + 1
   t = t[:len(t) - 1]
   t = t + "\n"
   with open("american-dobs.txt", "w") as f:
      f.write(t)
   i = i + 1
