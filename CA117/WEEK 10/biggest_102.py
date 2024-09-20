#!/usr/bin/env python3

def biggest(numbers):
    if len(numbers) == 1:
        return numbers[0]
    if numbers[1] > numbers[0]:
        return biggest(numbers[1:])
    else:
        numbers.remove(numbers[1])
        return biggest(numbers)

