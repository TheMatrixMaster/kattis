cpr = list(input())

parsed = [int(c) for c in cpr if c != '-']
multi = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]

y = sum([(parsed[i] * multi[i]) for i in range(10)])

if y % 11 == 0:
    print(1)
else:
    print(0)