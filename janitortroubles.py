"""
Brahmagupta's formula

calculates the area of a circular cyclic quadrilateral. 
A cyclic quadrilateral has all vertices lying on circle.
A cyclic quadrilateral maximizes the area of a quadrilateral
A cyclic quadrilateral has property such that opposite angles are supplementary (add up to 180deg)
"""

from math import sqrt

a, b, c, d = map(int, input().split(' '))

s = (a + b + c + d) / 2

print(sqrt((s-a)*(s-b)*(s-c)*(s-d)))