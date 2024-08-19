#!/usr/bin/env python3

s = input() + "-"
n = int(input())
s *= n
print(s[0:len(s) - 1])
#print((s + "-") * (n - 1) + s * (n -(n - 1)))
