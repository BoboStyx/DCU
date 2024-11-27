#!/usr/bin/env python3

n = int(input())

print((n - (n // 10000 * 10000) - (n % 100)) // 100)
