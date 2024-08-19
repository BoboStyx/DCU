#!/usr/bin/env python3

import sys

class Graph(object):
    def __init__(self, V):
        self.V = V
        self.adj = {}
        for i in range(V):
            self.adj[i] = []
    def add_edge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)

class DFSPaths(object):
    def __init__(self, g):
        self.g = g
        self.visited = [False] * g.V
        self.islands = 0

    def dfs(self, s):
        self.visited[s] = True
        for v in self.g.adj[s]:
            if not self.visited[v]:
                self.dfs(v)

    def findIslands(self):
        for i in range(self.g.V):
            if not self.visited[i]:
                self.islands += 1
                self.dfs(i)
        return self.islands

V = int(sys.stdin.readline())
lines = sys.stdin.readlines()
 
graph = Graph(V)

for line in lines:
    line = [int(x) for x in line.split()]
    graph.add_edge(line[0], line[1])

dfs = DFSPaths(graph)
print(dfs.findIslands())
