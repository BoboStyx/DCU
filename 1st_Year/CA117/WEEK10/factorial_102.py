#!/usr/bin/env python3

def factorial(number):
    if number == 0:
        return 1
    return number * factorial(number - 1)
