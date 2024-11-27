#!/usr/bin/env python3

class Meeting(object):
    def __init__(self, hour, minute, duration):
        self.hour = hour
        self.minute = minute
        self.duration = duration
    def __eq__(self, other):
        return self.hour == other.hour
    def __gt__(self, other):
        return self.hour > other.hour
    def __str__(self):
        if self.hour < 10:
            self.hour = '0' + str(self.hour)
        if self.minute < 10:
            self.minute = '0' + str(self.minute)
        return '{:2}:{:2} ({} minutes)'.format(self.hour, self.minute, self.duration)

class Schedule(object):
    def __init__(self):
        self.schedule = []
    def add(self, meeting):
        self.schedule.append(meeting)
    def __str__(self):
        self.schedule = sorted(self.schedule)
        meetings = len(self.schedule)
        schedule = [str(meet) for meet in self.schedule]
        schedule = '\n'.join(schedule)
        return 'Schedule\n--------\n{}\nMeetings today: {}'.format(schedule, meetings) 
