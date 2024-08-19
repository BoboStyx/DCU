#!/usr/bin/env python3

import sys

for email in sys.stdin:
   email = email.split(".")
   first_name = email[0].capitalize()
   last_name = email[1].capitalize()
   i = 0
   while i < len(last_name) and ("a" <= last_name[i] <= "z") or ("A" <= last_name[i] <= "Z"):
      i = i + 1
   last_name = last_name[:i].capitalize()
   print(first_name + " " + last_name)
