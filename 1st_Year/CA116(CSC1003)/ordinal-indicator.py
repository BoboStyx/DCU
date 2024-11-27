#!/usr/bin/env python3

n = int(input())

if (n % 10 == 1) and (n % 100 != 11):
   print("st")
elif (n % 10 == 2) and (n % 100 != 12):
   print("nd")
elif (n % 10 == 3) and (n % 100 != 13):
   print("rd")
else:
   print("th")
