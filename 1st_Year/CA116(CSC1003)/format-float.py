#!/usr/bin/env python3

s = input()
prefix = ""

if s[0] == "-":
   s = s[1:]
   prefix = prefix + "-"

i = 0
while i < len(s) and s[i] != ".":
   i = i + 1

if i == len(s):
   s = s + "." + "0"
elif i < len(s) and s[i] == s[len(s) - 1]:
   s = s + "0"
elif i < len(s) and s[i] == s[0]:
   s = "0" + s

s = prefix + s

print(s)
