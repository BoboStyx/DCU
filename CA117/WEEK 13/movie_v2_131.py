#!/usr/bin/env python3

class Actor(object):
    def __init__(self, name, nationality, fee):
        self.name = name
        self.nationality = nationality
        self.fee = fee
    def __str__(self):
        return 'Name: {}\nNationality: {}\nFee: {}'.format(self.name, self.nationality, self.fee)

class Movie(object):
    def __init__(self, title, duration):
        self.title = title
        self.duration = duration
        self.actors = {}
        self.payroll = 0
    def add(self, actor):
        self.actors[actor.name] = actor
        self.payroll += actor.fee
    def remove(self, actor):
        if actor in self.actors:
            self.payroll -= self.actors[actor].fee
            self.actors.pop(actor)
    def lookup(self, actor):
        if actor in self.actors:
            return self.actors[actor]
        else:
            return None
    def __str__(self):
        return 'Title: {}\nDuration: {} minute(s)\nCast: {}\nPayroll: {}'.format(self.title, self.duration, ', '.join(sorted(self.actors.keys())), self.payroll)
