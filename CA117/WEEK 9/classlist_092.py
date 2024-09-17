#!/usr/bin/env python3

class Student(object):
    def __init__(self, name, sid, modules):
        self.name = name
        self.sid = sid
        self.modlist = {module:mark for (module, mark) in modules}
    def average(self):
        grades = [mark for mark in self.modlist.values()]
        self.avg = sum(grades) / len(grades)
        return self.avg
    def __str__(self):
        modules = ', '.join(sorted(self.modlist.keys()))
        return f'Name: {self.name}\nID: {self.sid}\nModules: {modules}\nAverage mark: {self.average():.0f}'

class Classlist(object):
    def __init__(self):
        self.classlist = {}
    def add(self, student):
        self.classlist[student.average()] = student
    def __str__(self):
        classlist = []
        sort_avg = sorted([float(avg) for avg in self.classlist.keys()], reverse=True)
        for avg in sort_avg:
            classlist.append(str(self.classlist[avg]))
        classlist = '\n'.join(classlist)
        return classlist
