import heapq
import bisect
from collections import defaultdict


m = defaultdict(list)
n = int(input())
r = []

for _ in range(n):

    raw = input().split(' ')

    if raw[0] == 'add':
        key, value = map(int, raw[1:])
        heapq.heappush(m[key], -value)

    else:
        total = 0
        energy = int(raw[1])
        keys = sorted(m.keys())

        while m:
            i = bisect.bisect_right(keys, energy)

            if i:
                total -= heapq.heappop(m[keys[i-1]])
                energy -= keys[i-1]

                if not m[keys[i-1]]:
                    del m[keys[i-1]]
                    del keys[i-1]
            else:
                break

        r.append(total)

    
for t in r:
    print(t)
