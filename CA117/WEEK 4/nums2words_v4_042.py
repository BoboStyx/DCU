#!/usr/bin/env python3

import sys

numbering = {0:"zero", 1:"one", 2:"two", 3:"three", 4:"four", 5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine", 10:"ten", 11:"eleven", 12:"twelve", 13:"thirteen", 15:"fifteen", 18:"eighteen", 20:"twenty", 30:"thirty", 40:"forty", 50:"fifty", 80:"eighty", 100: "one hundred"}

for line in sys.stdin:
    t = ""
    numbers = line.split()
    for number in numbers:
        integer = int(number)
        if integer in numbering:
            t += numbering[integer] + " "
        elif integer not in numbering:
            if (integer // 10) == 1:
                t += numbering[integer % 10] + "teen" + " "
            elif integer % 10 != 0 and integer // 10 * 10 not in numbering:
                t += numbering[integer // 10] + "ty-" + numbering[integer % 10] + " "
            elif integer // 10 * 10 in numbering:
                t += numbering[integer // 10 * 10] + "-" + numbering[integer % 10] + " "
            elif integer % 10 == 0:
                t += numbering[integer // 10] + "ty" + " "
    print(t.strip())



