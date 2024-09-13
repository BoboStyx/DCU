#!/usr/bin/env python3

import sys

lines = sys.stdin.readlines()

def time_to_seconds(t):
    mins, secs = t.split(":")
    return int(mins) * 60 + int(secs)

def tagger(item):
    return time_to_seconds(item[1])

d = {}
for line in lines:
    try:
        token = line.strip().split()
        name = token[0]
        times = token[1:]
        d[name] = min(times, key=time_to_seconds)
    except ValueError:
        continue
    
k, v = min(d.items(), key=tagger)
print(f'{k} : {v}')

