n = int(input())

for _ in range(n):
    
    b, p = map(float, input().split(' '))
    
    abpm = 60 / (p / b)
    bpm = 60 * b / p
    
    minbpm = bpm - abpm
    maxbpm = bpm + abpm
    
    print(minbpm, bpm, maxbpm)