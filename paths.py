from collections import Counter

def color_arr_to_bkey(arr):
    return sum([10**(k-1) for k in arr])

def is_bkeys_disjoint(k1, k2):
    k12 = str(k1+k2)
    k1 = str(k1)
    k2 = str(k2)
    expected = k1.count('1') + k2.count('1')
    return k12.count('1') == expected

n, m, k = map(int, input().split(' '))

colors = list(map(int, input().split(' ')))

counter = 0
edges = [[] for _ in range(n)]
table = { i: Counter() for i in range(n) }
nodes = set(table.keys())

for _ in range(m):
    v1, v2 = map(int, input().split(' '))
    edges[v1-1].append(v2-1)
    edges[v2-1].append(v1-1)

def search(v, s, used_colors, nodeh):
    global table, counter, nodes
    if v in nodeh: return
    elif colors[v] in used_colors: return
    elif v != s and v not in nodes:
        for k1 in table[v]:
            k2 = color_arr_to_bkey(used_colors)
            if is_bkeys_disjoint(k1, k2):
                table[s][k1+k2] += table[v][k1]
                counter += table[v][k1]
    else:
        nnodeh = [n for n in nodeh] + [v]
        ncoloru = [x for x in used_colors] + [colors[v]]

        table[s][color_arr_to_bkey(ncoloru)] += 1

        if v != s: counter += 1

        children = edges[v]
        for c in children:
            search(c, s, ncoloru, nnodeh)

while nodes:
    node = nodes.pop()
    search(node, node, [], [])

    for n in edges[node]:
        if n in nodes:
            search(n, n, [], [])
            nodes.discard(n)
    
print(counter)

