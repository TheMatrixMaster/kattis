from collections import defaultdict

def compute_sum(g: defaultdict, t: int) -> int:
    s = 0
    spares = []

    for i in range(t-1, -1, -1):
        orig = max(g[i], default=0)
        over = max(spares, default=0)

        if orig == over == 0: continue
        elif orig >= over:
            s += orig
            g[i].remove(orig)
            spares.extend(g[i])
        else:
            s += over
            spares.remove(over)
            spares.extend(g[i])

    return s


tests = [
    ((5, {0: [200], 1: [100], 2: [600, 500], 3: [], 4: [500]}), 1800),
    ((5, {0: [150], 1: [100, 150], 2: [50, 100], 3: [50], 4: []}), 450),
    ((4, {0: [1200], 1: [1000], 2: [500, 2000], 3: [], 4: []}), 4200),
    ((4, {0: [1000], 1: [500, 2000], 2: [], 3: [], 4: []}), 3000),
]

def run_tests():

    for (t, g), res in tests:
        try:
            r = compute_sum(g, t)
            assert r == res
        except AssertionError as err:
            print(g, t)
            raise err
    

if __name__ == '__main__':
    n, t = map(int, input().split(' '))
    g = defaultdict(list)

    for _ in range(n):
        m, d = map(int, input().split(' '))
        g[d].append(m)

    print(compute_sum(g, t))


