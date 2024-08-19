#!/usr/bin/env python3

servers = []
duration = 1000

line = input()
while line != "end":
   start_time = int(line)
   i = 0
   while i < len(servers) and start_time < servers[i]:
      i += 1
   if i < len(servers):
      servers[i] = start_time + duration
   else:
      servers.append(start_time + duration)
   line = input()

print(len(servers))
