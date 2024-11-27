#!/usr/bin/env python3

import sys

tasks = sys.stdin.read().split()
users = {}
summary = {}

i = 0
while i < len(tasks):
   task = tasks[i]
   incr = 0
   while incr < len(task) and task[incr] != "/":
      incr = incr + 1
   user = task[:incr]
   if user not in users:
      users[user] = 0
   j = len(task) - 1
   while j != 0 and task[j] != ".":
      j = j - 1
   answer = task[j + 1:]
   task = task[:j]
   if task not in summary and answer == "correct":
      summary[task] = answer
      users[user] = users[user] + 1
   elif task not in summary:
      summary[task] = answer
   elif task in summary and summary[task] != answer and answer == "incorrect":
      users[user] = users[user] - 1
      summary[task] = answer
   elif task in summary and summary[task] != answer and answer == "correct":
      users[user] = users[user] + 1
      summary[task] = answer
   i = i + 1

for user in users:
   print(user, users[user])
