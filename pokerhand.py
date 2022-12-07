from collections import Counter

cards = list(input().split(' '))

cards = [c[0] for c in cards]

print(Counter(cards).most_common()[0][1])