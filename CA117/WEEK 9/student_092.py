#!/usr/bin/env python3

class Student(object):
    def __init__(self, name, sid, modules):
        self.name = name
        self.sid = sid
        self.modlist = {module:mark for (module, mark) in modules}
    def average(self):
        grades = [mark for mark in self.modlist.values()]
        average = sum(grades) / len(grades)
        return average
    def __str__(self):
        modules = ', '.join(sorted(self.modlist.keys()))
        return f'Name: {self.name}\nID: {self.sid}\nModules: {modules}\nAverage mark: {self.average():.0f}'
