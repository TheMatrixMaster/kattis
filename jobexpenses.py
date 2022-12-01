n = int(input())

if (n > 0):

    raw = list(map(int, input().split(' ')))
    parsed = [x for x in raw if x < 0]

    if parsed:
        print(-(sum(parsed)))
    else:
        print(0)

else:

    print(0)