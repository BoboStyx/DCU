#!/usr/bin/env python3

def smallest(numbers):
    if len(numbers) == 1:
        return numbers[0]
    if numbers[1] < numbers[0]:
        return smallest(numbers[1:])
    else:
        numbers.remove(numbers[1])
        return smallest(numbers)

