#!/usr/bin/env python3

import math
import sys

from math import pi

for numbers in sys.stdin:
   number = numbers.strip()
   print(f'{pi:.{number}f}')
