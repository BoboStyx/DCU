#!/usr/bin/env python3

class Student(object):
    def set_attributes(self, sid, name, modlist):
        self.sid = sid
        self.name = name
        self.modlist = modlist
    def add_module(self, module):
        if module not in modlist:
            (self.modlist).append(module)
    def del_module(self, module):
        (self.modlist).remove(module)
    def print_attributes(self):
        print('ID: {}'.format(self.sid))
        print('Name: {}'.format(self.name))
        print(f'Modules: {", ".join(self.modlist)}')
