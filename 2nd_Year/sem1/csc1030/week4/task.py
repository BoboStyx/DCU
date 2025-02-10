#!/usr/bin/env python3

def sum_q1(n):
    if n == 0:
        return 0
    return n + sum_q1(n - 1)

i = 2
def reverse_int(n, i):
    if n == 0:
        return 0
    return (n % 10) * (10 ** i) + (reverse_int(n // 10, i - 1))

s = "hello"
length = len(s) - 1
def reverse_str(s, length):
    if length == -1:
        return ""
    return s[length] + reverse_str(s, length - 1)

def inverse_list(my_list):
    if len(my_list) == 1:
        return [my_list[0]]
    return [my_list[-1]] + inverse_list(my_list[:-1])


def multiply(n, multiplier):
    if multiplier == 0:
        return 0
    if multiplier > 0:
        return multiply(n, multiplier - 1) + n
    elif multiplier < 0:
        return multiply(n, multiplier + 1) - n

def is_heteromecic(num, increment=1):
    if increment * (increment + 1) > num:
        return False
    elif increment * (increment + 1) == num:
        return True
    return is_heteromecic(num, increment + 1)

def length_string(string, increment=0):
    if string == "":
        return increment
    return length_string(string[1:], increment + 1)
