#!/usr/bin/env python3

class Contact(object):
    def __init__(self, name, phone, email):
        self.name = name
        self.phone = phone
        self.email = email
    def __str__(self):
        return '{} {} {}'.format(self.name, self.phone, self.email)

class Contactlist(object):
    def __init__(self):
        self.contactlist = {}
        self.list = []
    def add(self, contact):
        self.contactlist[contact.name] = contact
        (self.list).append(str(contact))
    def remove(self, name):
        if name in self.contactlist:
            (self.list).remove((str(self.contactlist[name])))
            (self.contactlist).pop(name)
    def get(self, name):
        if name in self.contactlist:
            return self.contactlist[name]
        else:
            return None
    def __str__(self):
        self.list = "\n".join(sorted(self.list))
        return f'Contact list\n------------\n{(self.list)}'

