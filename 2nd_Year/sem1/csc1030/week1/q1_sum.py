#!/usr/bin/env python3

total = 0

def q1_sum(list_of_numbers, total):
    for numbers in list_of_numbers:
        for number in numbers:
            if number % 2 == 0:
                total += number
    return total

q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]], total)

