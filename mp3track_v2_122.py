#!/usr/bin/env python3

class MP3Track(object):
    def __init__(self, title, duration, artists):
        self.title = title
        self.duration = duration
        self.artists = artists
    def __str__(self):
        return 'Title: {}\nBy: {}\nDuration: {}'.format(self.title, ', '.join(self.artists), self.duration)
