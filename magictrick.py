from collections import Counter

c = Counter(str(input()))

if c.most_common(1)[0][1] > 1:
    print(0)
else:
    print(1)
