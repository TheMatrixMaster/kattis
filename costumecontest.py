from collections import Counter

n = int(input())

c = Counter()

for _ in range(n):
    c[input()] -= 1

max = c.most_common()[0][1]
winners = sorted([x[0] for x in c.most_common() if x[1] == max])

for w in winners:
    print(w)