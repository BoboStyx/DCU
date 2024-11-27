#!/usr/bin/env python3

file_name = "input.txt"

with open(file_name) as f:
   s = f.read()

print(s[0:len(s) - 1])
