#!/usr/bin/env python3

a = int(input())
b = int(input())
c = int(input())
axa = a * a
bxb = b * b
cxc = c * c

print((axa + bxb == cxc) or (bxb + cxc == axa) or (cxc + axa == bxb))
