#!/usr/bin/env python3

import sys

phonebook = {}

with open(sys.argv[1]) as f:
    contacts = f.readlines()

for lines in contacts:
    line = lines.strip().split()
    phonebook[line[0]] = [line[1], line[2]]

for names in sys.stdin:
    name = names.strip()
    print("Name:", name)
    if name in phonebook:
        print("Phone:", phonebook[name][0])
        print("Email:", phonebook[name][1])
    elif name not in phonebook:
        print("No such contact")
