#!/usr/bin/env python3

decimal = int(input())
t = ""
n = 0

i = 0
while decimal > 0:
   if decimal % 2 == 1:
      decimal = decimal // 2
      n = "1"
   else:
      decimal = decimal // 2
      n = "0"
   t = n + t
   i = i + 1

print(t)
