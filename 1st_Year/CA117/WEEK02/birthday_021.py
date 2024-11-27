#!/usr/bin/env python3

import sys
import calendar


poem = ["Monday's child is fair of face.", "Tuesday's child is full of grace.", "Wednesday's child is full of woe.", "Thursday's child has far to go.", "Friday's child is loving and giving.", "Saturday's child works hard for a living.", "Sunday's child is fair and wise and good in every way."]
for lines in sys.stdin:
    line = lines.split()
    year = int(line[2])
    month = int(line[1])
    day = int(line[0])
    print(f'You were born on a {poem[calendar.weekday(year, month, day)].split(" ")[0][:-2]:s} and {poem[calendar.weekday(year, month, day)]:s}')
