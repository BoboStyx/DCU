#!/usr/bin/env python3

class Customer(object):
    def __init__(self, name, number, balance=0.00):
        self.name = name
        self.number = number
        self.balance = balance
    def __str__(self):
        return 'Name: {}\nNumber: {}\nBalance: {:.2f}'.format(self.name, self.number, self.balance)
