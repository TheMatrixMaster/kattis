from sys import stdin

lines = stdin.read().splitlines()

scores = []
score = 0

for line in lines:
    if line:
        s = int(line)
        score += s
    else:
        scores.append(score)
        score = 0

if score:
    scores.append(score)

print(sum(sorted(scores, reverse=True)[:3]))