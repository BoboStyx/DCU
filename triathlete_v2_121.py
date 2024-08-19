#!/usr/bin/env python3

class Triathlete(object):
    def __init__(self, name, tid):
        self.name = name
        self.tid = tid
        self.total = 0
        self.sport = {}
    def add_time(self, activity, seconds):
        self.sport[activity] = seconds
        self.total += int(seconds)
    def get_time(self, activity):
        return self.sport[activity]
    def __str__(self):
        return 'Name: {}\nID: {}\nRace time: {}'.format(self.name, self.tid, self.total)
