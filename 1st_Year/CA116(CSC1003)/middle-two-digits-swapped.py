#!/usr/bin/env python3

n = int(input())

print((((n - ((n // 10000) * 10000)) // 100) % 10) * 10 + (n % 10000 // 1000))
