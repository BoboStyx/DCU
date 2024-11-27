#!/usr/bin/env python3

class Point(object):
    def __init__(self, x=None, y=None):
        if x == None:
            x = 0.0
        if y == None:
            y = 0.0
        self.x = x
        self.y = y
    def distance(self, p2):
        distance = ((self.x - p2.x) ** 2 + (self.y - p2.y) ** 2) ** .5
        return distance
    def __str__(self):
        return '({:.1f}, {:.1f})'.format(self.x, self.y)
