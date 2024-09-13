#!/usr/bin/env python3

import sys

dictionary = {"o":"es", "s":"es", "z":"es", "ch":"es", "sh":"es", "x":"es",}
vowels = ["o", "i", "e", "a", "u"]


for lines in sys.stdin:
   line = lines.strip()
   if line[-1] in dictionary:
      print(line + dictionary[line[-1]])
   elif line[-2:] in dictionary:
      print(line + dictionary[line[-2:]])
   elif line[-1] == "f":
      print(line[:-1] + "ves")
   elif line[-2:] == "fe":
      print(line[:-2] + "ves")
   elif line[-1] == "y" and line[-2] not in vowels:
      print(line[:-1] + "ies")
   else:
      print(line + "s")
