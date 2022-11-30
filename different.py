from sys import stdin

lines = stdin.read().splitlines()

for line in lines:
    a, b = map(int, line.strip().split(' '))
    print(abs(a - b))