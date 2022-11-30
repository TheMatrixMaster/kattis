n, m = map(int, input().strip().split(' '))

s = 0

jack = set()

while n > 0:
    jack.add(int(input()))
    n -= 1

raw = input()

while raw.isdigit():
    if int(raw) in jack:
        s += 1

    raw = input()

print(s)