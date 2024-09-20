#!/usr/bin/env python3

import sys

stairs = int(sys.stdin.readline().strip())
jumps = sys.stdin.readline().split()
jump2 = 0
if len(jumps) == 2:
    jump1, jump2 = int(jumps[0]), int(jumps[1])
else:
    jump1 = int(jumps[0])

def Jumper(stairs):
    if stairs == 0:
        return 1
    elif stairs < 0:
        return 0
    if jump2 != 0:
        return Jumper(stairs - jump1) + Jumper(stairs - jump2)
    else:
        return Jumper(stairs - jump1)

print(Jumper(stairs))

