#!/usr/bin/env python3

class Queue(object):
    def __init__(self):
        self.queue = []
    def enqueue(self, value):
        return self.queue.append(value)
    def dequeue(self):
        return self.queue.pop(0)
    def first(self):
        return self.queue[0]
    def is_empty(self):
        return len(self.queue) == 0
    def __len__(self):
        return len(self.queue)
