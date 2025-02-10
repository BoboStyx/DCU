#!/usr/bin/env python3

total = 0
vowels = 'aeiouAEIOU'

def q1_sum(list_of_numbers, total):
    for numbers in list_of_numbers:
        for number in numbers:
            if number % 2 == 0:
                total += number
    return total

q1_sum([[1, 0, 2], [5, 5, 7], [9, 4, 3]], total)

def move_vow(message, s):
    i = 0
    while i < len(message):
        if message[i] in vowels:
            s += message[i]
            if i == 0:
                message = message[:i]
            elif i < len(message) - 1:
                message = message[:i] + message[i + 1:]
            else:
                message = message[:i]
        i += 1
    return s + message

print(move_vow('This is DCU!', s=''))

class Memories(object):
    __init__(self, 
