from collections import Counter

n, t = map(int, input().split(' '))

a = list(map(int, input().split(' ')))

if __name__ == '__main__':
    if t == 1:
        d = {}
        solved = False
        for v in a:
            if v in d:
                print("Yes")
                solved = True
                break
            else:
                d[7777-v] = v

        if not solved:
            print("No")

    elif t == 2:
        if len(set(a)) == len(a):
            print('Unique')
        else:
            print('Contains duplicate')

    elif t == 3:
        c = Counter(a).most_common(1)
        if c[0][1] > n // 2:
            print(c[0][0])
        else:
            print(-1)  

    elif t == 4:
        b = sorted(a)
        middle = n // 2
        if n % 2 == 1:
            print(b[middle])
        else:
            print(b[middle-1], b[middle])

    elif t == 5:    

        b = []
        
        for v in a:
            if 100 <= v <= 999:
                b.append(v)

        for v in sorted(b):
            print(v, end=' ') 

        print()