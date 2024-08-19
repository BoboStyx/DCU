#!/usr/bin/env python3

import sys

table = sys.stdin.readlines()

maxlen = 0
for line in table:
   team = " ".join(line.split()[1:-8])
   if len(team) > maxlen:
      maxlen = len(team)

print(f"{'POS':>3} {'CLUB':{maxlen}} {'P':>2} {'W':>3} {'D':>3} {'L':>3} {'GF':>3} {'GA':>3} {'GD':>3} {'PTS':>3}")

for line in table:
   tokens = line.split()
   print(f'{tokens[0]:>3} {" ".join(tokens[1:-8]):{maxlen}} {tokens[-8]:>2} {tokens[-7]:>3} {tokens[-6]:>3} {tokens[-5]:>3} {tokens[-4]:>3} {tokens[-3]:>3} {tokens[-2]:>3} {tokens[-1]:>3}')
