#!/usr/bin/env python3

import sys

guesses = sys.stdin.read().split()
check = int(guesses[0])
trust = True

for word in guesses:
    if word.isdigit():
        number = int(word)
    if word == "higher":
        if check > number:
            trust = False
        elif check <= number:
            check = number
    if word == "lower":
        if check > number:
            trust = False
        elif check >= number:
            check = number
    if word == "correct":
        break

if trust:
    print("Bert can be trusted")
else:
    print("Bert is not to be trusted")
