#!/usr/bin/env python3

import sys

histogram = []
i = 0
while i < 20:
   histogram.append([" "] * 20)
   i = i + 1

max = 0
freq = [0] * 20
s = sys.stdin.read().split()

i = 0
while i < len(s):
   n = int(s[i])
   time = freq[n]
   histogram[time][n] = '*'
   freq[n] += 1
   if max < freq[n]:
      max = freq[n]
   i = i + 1

j = max - 1
while j >= 0:
   p = 0
   k = 0
   while k < len(histogram[j]):
      if histogram[j][k] == '*':
         p = k
      k = k + 1
   print(' | ' + ''.join(histogram[j][:p + 1]))
   j = j - 1

print(' ' + '-' * 23)
