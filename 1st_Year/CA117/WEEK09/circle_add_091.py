#!/usr/bin/env python3

class Point(object):
    def __init__(self, x=0, y=0):
        self.x = float(x)
        self.y = float(y)
    def midpoint(self, other):
        midpointx = (self.x + other.x) / 2
        midpointy = (self.y + other.y) / 2
        return Point(midpointx, midpointy)
    def __str__(self):
        return f'({self.x:.1f}, {self.y:.1f})'

class Circle(object):
    def __init__(self, point=None, radius=1):
        if point == None:
            self.centre = Point(0,0)
        else:
            self.centre = point
        self.radius = float(radius)
    def __add__(self, other):
        c1, c2 = self.centre, other.centre
        c3 = c1.midpoint(c2)
        radius = self.radius + other.radius
        return Circle(c3, radius)
    def __str__(self):
        return f'Centre: {self.centre}\nRadius: {self.radius:.0f}'
