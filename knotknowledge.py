n = int(input())

knots = set(map(int, input().split(' ')))

known = set(map(int, input().split(' ')))

unknown = knots.difference(known)

print(unknown.pop())