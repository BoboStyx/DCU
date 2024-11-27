#!/usr/bin/env python3

def matcher(s):
    brackets = {
            ')' : '(', '}' : '{', ']' : '['
            }
    stack = []
    for c in s:
        if c in brackets:
            if stack:
                if stack.pop() == brackets[c]:
                    pass
                else:
                    return False
            else:
                return False
        else:
            stack.append(c)
    return not stack
