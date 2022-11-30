lines, cols, classes = map(int, input().split(' '))

rows = []

for line in range(lines):
    rows.append(list(input()))
    
colors = []

for col in zip(*rows):
    scol = set(col)
    added = False
    for i, color in enumerate(colors):
        if not color.isdisjoint(scol):
            colors[i] = color.union(scol)
            added = True
    
    if not added:
        colors.append(scol)

print(len(colors))