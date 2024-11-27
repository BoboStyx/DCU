#!/usr/bin/env python3

class MP3Track(object):
    def __init__(self, title, duration):
        self.title = title
        self.duration = duration
    def __str__(self):
        hours = self.duration // 60
        minutes = self.duration - hours * 60
        if minutes < 10:
            minutes = "0" + str(minutes)
        return 'Title: {}\nBy: {}\nDuration: {}:{}'.format(self.title, ', '.join(self.artists), hours, minutes)

class MP3Collection(object):
    def __init__(self):
        self.collection = {}
    def add(self, mp3track):
        if mp3track.title not in self.collection:
            self.collection[mp3track.title] = mp3track
    def lookup(self, mp3track):
        if mp3track in self.collection:
            return self.collection[mp3track]
        else:
            return None
    def remove(self, mp3track):
        if mp3track in self.collection:
            self.collection[mp3track] = None

