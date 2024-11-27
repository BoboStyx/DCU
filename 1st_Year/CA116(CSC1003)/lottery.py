#!/usr/bin/env python3

import sys

lottery = sys.argv[1:]
lucky = {}


i = 0
while i < len(lottery):
   number = lottery[i]
   if number not in lucky:
      lucky[number] = 0
   i = i + 1

tickets = sys.stdin.read().split("\n")
tickets = tickets[:len(tickets) - 1]

i = 0
while i < len(tickets):
   reward = 0
   ticket = tickets[i]
   ticket = ticket.split()
   j = 0
   while j < len(ticket):
      if ticket[j] in lucky:
         reward = reward + 1
      j = j + 1
   if reward == 0:
      print(0)
   if reward == 1:
      print(1)
   if reward == 2:
      print(5)
   if reward == 3:
      print(100)
   i = i + 1
