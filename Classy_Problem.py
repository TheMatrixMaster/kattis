n = int(input())

for i in range(n):
    lines = int(input())

    m = 0
    d = {}
    for j in range(lines):
        l = str(input())
        tmp = l.split(':')
        key, classes = tmp[0], tmp[1].strip()[:-6].split('-')
        d[key] = classes

        if len(classes) > m:
            m = len(classes)

    for k, v in d.items():
        if len(v) < m:
            d[k] = ((['middle'] * (m - len(v))) + v)

        d[k].reverse()

    out = sorted(d, key=lambda key: key)
    out = sorted(out, key=lambda key: d[key], reverse=True)

    for item in out:
        print(item)

    print("=" * 30)


