#!/usr/bin/env python3

import sys

text = sys.stdin.read()
count = 0

i = 0
while i < len(text):
   if text[i] == "." or text[i] == "!" or text[i] == "?" or text[i] == ",":
      count += 1
   i = i + 1

print(count)
