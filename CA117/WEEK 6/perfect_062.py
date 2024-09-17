#!/usr/bin/env python3

def get_divisors(num:int):
    divisors = []
    for i in range(1, num + 1):
        if num % i == 0:
            divisors.append(i)
    return divisors

def get_proper_divisors(num:int):
    divisors = get_divisors(num)
    divisors.pop()
    return divisors

def is_perfect(num:int):
    total = 0
    divisors = get_proper_divisors(num)
    for i in divisors:
        total += i
    if total == num:
        return True
    return False


