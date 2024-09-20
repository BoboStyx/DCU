#!/usr/bin/env python3

def reverse(array, alter=None):
    if alter == None:
        alter = []
    if len(array) == 0:
        return alter
    alter.append(array[len(array) - 1])
    return reverse(array[:len(array) - 1], alter)
