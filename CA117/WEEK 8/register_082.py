#!/usr/bin/env python3

class CashRegister(object):
    def __init__(self, count=0, total=0.00):
        self.total = total
        self.count = count
    def add_item(self, value):
        self.total += float(value)
        self.count += 1
    def clear(self):
        self.total = 0.00
        self.count = 0
    def __str__(self):
        return f'Items: {self.count}\nTotal: {self.total:.2f}'



