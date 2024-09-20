#!/usr/bin/env python3

import sys


for lines in sys.stdin:
    changes = []
    chess_set = lines.split()
    if int(chess_set[0]) != 2:
        changes.append(2 - int(chess_set[0]))
    else:
        changes.append(0)
    if int(chess_set[1]) != 2:
        changes.append(2 - int(chess_set[1]))
    else:
        changes.append(0)
    if int(chess_set[2]) != 4:
        changes.append(4 - int(chess_set[2]))
    else:
        changes.append(0)
    if int(chess_set[3]) != 4:
        changes.append(4 - int(chess_set[3]))
    else:
        changes.append(0)
    if int(chess_set[4]) != 4:
        changes.append(4 - int(chess_set[4]))
    else:
        changes.append(0)
    if int(chess_set[5]) != 16:
        changes.append(16 - int(chess_set[5]))
    else:
        changes.append(0)
    print(" ".join([str(n) for n in changes]))
