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
    def __eq__(self, other):
        return self.total == other.total
    def __gt__(self, other):
        return self.total > other.total
    def __lt__(self, other):
        return self.total < other.total
    def __str__(self):
        return 'Name: {}\nID: {}\nRace time: {}'.format(self.name, self.tid, self.total)

class Triathlon(object):
    def __init__(self):
        self.athletes = {}
    def add(self, triathlete):
        self.athletes[triathlete.tid] = triathlete
    def remove(self, tid):
        self.athletes.pop(tid)
    def lookup(self, tid):
        if tid in self.athletes:
            return self.athletes[tid]
        else:
            return None
