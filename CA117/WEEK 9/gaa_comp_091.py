#!/usr/bin/env python3

class Score(object):
    def __init__(self, goals=0, points=0):
        self.goals = goals
        self.points = points
    def __eq__(self, other):
        return self.goals * 3 + self.points == other.goals * 3 + other.points
    def __gt__(self, other):
        return self.goals * 3 + self.points > other.goals * 3 + other.points
    def __lt__(self, other):
        return self.goals * 3 + self.points < other.goals * 3 + other.points
    def __le__(self, other):
        return self.goals * 3 + self.points <= other.goals * 3 + other.points
    def __ge__(self, other):
        return self.goals * 3 + self.points >= other.goals * 3 + other.points
    def __str__(self):
        return f'{self.goals} goal(s) and {self.points} point(s)'
