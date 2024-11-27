#!/usr/bin/env python3

import sys

for passwords in sys.stdin:
   password = passwords.strip()
   count = 0
   dictionary = {"lower":False, "upper":False, "digits":False, "cases":False}
   i = 0
   while i < len(password):
      if password[i].islower() and dictionary["lower"] == False:
         count += 1
         dictionary["lower"] = True
      elif password[i].isalpha() and password[i].islower() == False and dictionary["upper"] == False:
         count += 1
         dictionary["upper"] = True
      elif password[i].isdigit() and dictionary["digits"] == False:
         count += 1
         dictionary["digits"] = True
      elif password[i].isdigit() == False and password[i].isalpha() == False and dictionary["cases"] == False:
         count += 1
         dictionary["cases"] = True
      i += 1
   print(count)
