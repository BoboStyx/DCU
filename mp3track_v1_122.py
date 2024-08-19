#!/usr/bin/env python3

class MP3Track(object):
    def __init__(self, title, duration):
        self.title = title
        self.duration = duration
    def __str__(self):
        return 'Title: {}\nDuration: {}'.format(self.title, self.duration)
