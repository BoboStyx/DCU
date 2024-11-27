#!/usr/bin/env python3

s = input()

t = ""

alphai = 0
i = 0
while i < len(s):
   ch = ord(s[i])
   if alphai % 2:
      if 97 <= ch and ch <= 122:
         ch = ch - 32
   else:
      if 65 <= ch <= 90:
         ch = ch + 32
   if (97 <= ch <= 122) or (65 <= ch <= 90):
      alphai = alphai + 1
   t = t + chr(ch)
   i = i + 1

print(t)
