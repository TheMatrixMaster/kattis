from math import sqrt

n = int(input())

b = 2**(2*(n-1)) 

print(int(3*b + 2*sqrt(b) + (sqrt(b)+1)**2))