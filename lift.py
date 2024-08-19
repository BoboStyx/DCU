#!/usr/bin/env python3

import sys

f, s, g, u, d = [int(x) for x in sys.stdin.readline().strip().split()]


def lift(curr, i):
    new = []
    for x in curr:
        up, down = x + u, x - d
        if up <= f and up not in new:
            new.append(up)
        if down > 0 and down not in new:
            new.append(down)
    i += 1
    if g in new:
        return i
    elif len(new) == 0 or [x for x in curr if x > g or x <= 0]:
        return "Sorry Sheila!"
    else:
        result = lift(new, i)
        if result is not None:
            return result
        else:
            return "Sorry Sheila!"
print(lift([s], 0))
