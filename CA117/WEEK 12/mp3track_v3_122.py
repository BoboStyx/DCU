#!/usr/bin/env python3

class MP3Track(object):
    def __init__(self, title, duration, artists):
        self.title = title
        self.duration = duration
        self.artists = artists
    def __str__(self):
        hours = self.duration // 60
        minutes = self.duration - hours * 60
        if minutes < 10:
            minutes = "0" + str(minutes)
        return 'Title: {}\nBy: {}\nDuration: {}:{}'.format(self.title, ', '.join(self.artists), hours, minutes)
