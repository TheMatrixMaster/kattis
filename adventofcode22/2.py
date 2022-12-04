from sys import stdin 

lines = stdin.read().splitlines()

dict1 = ['A', 'B', 'C']
dict2 = ['X', 'Y', 'Z']

score = 0

for line in lines:

    if line:
        a, b = str(line).strip().split(' ')

        aind = dict1.index(a)
        bind = dict2.index(b)

        if (bind - aind) % 3 == 1:
            # you win
            score += bind + 1 + 6
        elif (bind - aind) % 3 == 2:
            # you lose
            score += bind + 1
        else:
            score += bind + 1 + 3

print(score)