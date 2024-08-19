#!/usr/bin/env python3

import sys

ob = "( [ {".split()
cb = ") ] }".split()
d = {}
line = []

i = 0
while i < len(ob):
    d[cb[i]] = ob[i]
    i += 1

lines = []
input = sys.stdin.readline()
while input != "":
    output = []
    input = input.rstrip()
    lines.append(input)
    finding = []
    i = 0
    while i < len(input):
        cdin = input[i] in cb
        lencheck = len(finding) > 0
        if input[i] in ob:
            finding.append(input[i])
        elif cdin and lencheck and finding[len(finding) - 1] == d[input[i]]:
            finding.pop()
        elif cdin:
            output.append(str(len(lines) - 1) + " " + str(i))
        i += 1

    if len(finding) > 0:
        output.append(str(len(lines) - 1) + " " + str(i))
    position = 0
    i = 0
    while i < len(output):
        if i == 0 or int(output[i].split()[1]) < position:
            position = int(output[i].split()[1])
        i = i + 1

    if len(output) > 0:
        print(len(lines) - 1, position)
    input = sys.stdin.readline()
