#!/usr/bin/env python3

import sys

total = 0
nums = sys.stdin.read().split()

i = 0
while i < len(nums):
   number = int(nums[i])
   total = number + total
   i = i + 1

print(total)
