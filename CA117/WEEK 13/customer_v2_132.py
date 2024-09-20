#!/usr/bin/env python3

class Customer(object):
    def __init__(self, name, number, balance=0.00):
        self.name = name
        self.number = number
        self.balance = balance
    def withdraw(self, funds):
        if funds < self.balance:
            self.balance -= funds
    def lodge(self, funds):
        self.balance += funds
    def __str__(self):
        return 'Name: {}\nNumber: {}\nBalance: {:.2f}'.format(self.name, self.number, self.balance)

class Bank(object):
    def __init__(self):
        self.bank = {}
    def add(self, customer):
        self.bank[customer.number] = customer 
    def remove(self, number):
        if number in self.bank:
            self.bank.pop(number)
    def lookup(self, number):
        if number in self.bank:
            return self.bank[number]
        else:
            return None
