#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()


for line in lines:
   line = line.lower()
   original = ""
   for letter in line:
      if letter.isalnum():
         original += letter
   palindrome = original[::-1]
   if palindrome == original:
      print("True")
   else:
      print("False")
