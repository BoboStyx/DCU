#!/usr/bin/env python3

class Stack(object):
    def __init__(self):
        self.l = []
    def push(self, value):
        self.l.append(value)
    def top(self):
        return self.l[-1]
    def pop(self):
        return self.l.pop()
    def is_empty(self):
        return len(self.l) == 0
    def __len__(self):
        return len(self.l)
