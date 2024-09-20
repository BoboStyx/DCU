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
        self.times = []
    def add(self, triathlete):
        self.athletes[triathlete.tid] = triathlete
        self.times.append(triathlete.total)
    def remove(self, tid):
        self.athletes.pop(tid)
    def lookup(self, tid):
        if tid in self.athletes:
            return self.athletes[tid]
        else:
            return None
    def best(self):
        best = min(self.times)
        for tid in self.athletes:
            if self.athletes[tid].total == best:
                return self.athletes[tid]
    def worst(self):
        worst = max(self.times)
        for tid in self.athletes:
            if self.athletes[tid].total == worst:
                return self.athletes[tid]
    def __str__(self):
        triathletes = sorted([str(triathlete) for triathlete in self.athletes.values()])
        return '{}'.format("\n".join(triathletes))
