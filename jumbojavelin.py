n = int(input())

rods = [int(input()) for _ in range(n)]

print(sum(rods) - len(rods) + 1)