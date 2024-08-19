#!/usr/bin/env python3

class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = {}
        for v in range(self.V):
            self.adj[v] = []
    def addEdge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)
    def degree(self, v):
        return len(self.adj[v])
    def maxDegree(self):
        return max([self.degree(v) for v in self.adj])
    def avgDegree(self):
        return sum([self.degree(v) for v in self.adj]) / self.V
