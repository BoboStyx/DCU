#!/usr/bin/env python3

class Point(object):
    def set_attributes(self, x, y):
        self.x = float(x)
        self.y = float(y)
    def reflect(self):
        self.x = -1 * self.x
        self.y = -1 * self.y
    def print_attributes(self):
        print('x: {:.2f}'.format(self.x))
        print('y: {:.2f}'.format(self.y))
