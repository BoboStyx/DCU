#!/usr/bin/env python3

def calculator(s):
  s = s.split()
  stack = []
  for n in s:
    if n.replace(".", "").isnumeric():
      stack.append(float(n))
    elif n == "+":
      stack.append(stack.pop() + stack.pop())
    elif n == "*":
      stack.append(stack.pop() * stack.pop())
    elif n == "-":
      d1, d2 = stack.pop(), stack.pop()
      stack.append(d2 - d1)
    elif n == "/":
      d1, d2 = stack.pop(), stack.pop()
      stack.append(d2 / d1)
    elif n == "r":
      stack.append(stack.pop() ** 0.5)
    elif n == "n":
      stack.append(stack.pop() * -1)
  return stack.pop()
