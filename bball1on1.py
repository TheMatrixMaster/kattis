from collections import Counter

d = Counter()

_in = input()

for i, char in enumerate(_in[::2]):
    d[char] += int(_in[2*i+1])
    
print(d.most_common()[0][0])