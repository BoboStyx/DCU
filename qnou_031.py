#!/usr/bin/env python3

import sys

words = sys.stdin.read().split()

def qnou(word):
    print("Words with q but no u:", [word for word in words if "q" in word.lower() and  word.lower().count("q") != word.lower().count("qu")])
qnou(words)
