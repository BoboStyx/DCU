#!/usr/bin/env python3

import sys

quadrant = {(True, True): 1, (False, True): 4, (False, False): 3, (True, False): 2}

for lines in sys.stdin:
    x, y = lines.split()
    print(quadrant[(0 < int(x)), (0 < int(y))])
