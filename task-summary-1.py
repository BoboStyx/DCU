#!/usr/bin/env python3

import sys

tasks = sys.stdin.read().split()
summary = {}

i = 0
while i < len(tasks):
   task = tasks[i]
   j = len(task) - 1
   while j != 0 and task[j] != ".":
      j = j - 1
   summary[task[:j]] = task[j + 1:]
   i = i + 1

for task in summary:
   if summary[task] == "correct":
      print(task)
