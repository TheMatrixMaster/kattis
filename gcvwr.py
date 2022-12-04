G, T, N = map(int, input().split(' '))

items = list(map(int, input().split(' ')))

cap = 0.9 * (G - T)

print(int(cap - sum(items)))

