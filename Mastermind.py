from collections import Counter

raw = str(input()).strip().split(' ')
n, p, q = int(raw[0]), raw[1].strip(), raw[2].strip()


r, s = 0, 0

p_count = Counter()
q_count = Counter()

for i in range(n):

    if p[i] == q[i]:
        r += 1
    else:
        p_count[p[i]] += 1
        q_count[q[i]] += 1

intersection = p_count & q_count
s = sum(intersection.values())

print(r, s)


