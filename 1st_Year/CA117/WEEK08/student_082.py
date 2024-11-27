#!/usr/bin/env python3

class Student(object):
    def __init__(self, sid, name, modlist=None):
        if modlist == None:
            modlist = []
        self.sid = sid
        self.name = name
        self.modlist = modlist
    def add_module(self, module):
        if module not in self.modlist:
            self.modlist.append(module)
    def del_module(self, module):
        self.modlist.remove(module)
    def __str__(self):
        self.modlist = sorted(self.modlist)zaza
        return f'ID: {self.sid}\nName: {self.name}\nModules: {", ".join(self.modlist)}'
