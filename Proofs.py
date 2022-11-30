n = int(input())

my_set = set()
success = True

for i in range(n):
    line = str(input()).strip().split(' ')

    hyp = []
    known = []

    passed = False
    for item in line:
        if item == '->':
            passed = True
            continue

        if passed:
            known.append(item)
        else:
            hyp.append(item)

    for h in hyp:
        if h not in my_set:
            passed = False

    if passed:
        for k in known:
            my_set.add(k)
    else:
        print(i+1)
        success = False
        break


if success:
    print("correct")
