#!/usr/bin/env python3

class BankAccount(object):
    def __init__(self, balance=0.00):
        self.balance = balance
    def deposit(self, value):
        self.balance += float(value)
    def withdraw(self, value):
        if self.balance >= value:
            self.balance -= float(value)
    def __str__(self):
        self.balance = float(self.balance)
        return 'Your current balance is {:.2f} euro'.format(self.balance)

