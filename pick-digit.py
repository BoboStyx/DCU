#!/usr/bin/env python3

n = int(input())
p = int(input())

print((n % 10 ** (p + 1)) // (10 ** p))
