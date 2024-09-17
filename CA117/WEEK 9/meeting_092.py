#!/usr/bin/env python3

class Meeting(object):
    def __init__(self, hour, minute, duration):
        self.hour = hour
        self.minute = minute
        self.duration = duration
    def __str__(self):
        if self.hour < 10:
            self.hour = '0' + str(self.hour)
        if self.minute < 10:
            self.minute = '0' + str(self.minute)
        return '{:2}:{:2} ({} minutes)'.format(self.hour, self.minute, self.duration)
