#!/usr/bin/env python3

def sumup(number):
    if number == 0:
        return 0
    return number + sumup(number - 1)
