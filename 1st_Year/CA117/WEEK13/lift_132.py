#!/usr/bin/env python3


import sys

integers = sys.stdin.readline().split()

integers = [int(n) for n in integers]

count = 0
f, s, g, u, d = integers

def lift(s, count):
    if s == g:
        return count
    if s <= g and s != s + u and s + u <= f:
        count += 1
        return lift(s + u, count)
    if s != s - d and s - d >= 0:
        count += 1
        return lift(s - d, count)
    return "Sorry Sheila!"

print(lift(s, count))
