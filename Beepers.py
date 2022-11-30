import numpy as np
import itertools

n = int(input())

for i in range(n):

    width, height = map(int, str(input()).split(' '))

    start_x, start_y = map(int, str(input()).split(' '))

    m = int(input())

    # Compute coordinate map

    coords = []
    coords_map = {}

    for j in range(m):
        tmp = tuple(map(int, str(input()).split(' ')))
        coords.append(tmp)
        coords_map[frozenset((tmp,))] = j

    # Compute pairwise distances for all coordinates
    dist = np.zeros((len(coords), len(coords)))

    for i1, c1 in enumerate(coords):
        for i2, c2 in enumerate(coords[:i1]):
            if i1 == i2:
                dist[i1][i2] = 0
            else:
                dist[i1][i2] = abs(c2[1]-c1[1]) + abs(c2[0]-c1[0])

    # Compute all subsets of size 0 < k < len(coords)
    subsets = {}
    counter = 0

    for size in range(1, len(coords)):
        sub = list(itertools.combinations(coords, size))
        for index, s in enumerate(sub):
            frz = frozenset(s)
            subsets[frz] = counter
            counter += 1

    L = np.zeros((counter, len(coords)-1))

    print(L)



