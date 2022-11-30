from sys import stdout

range = list(range(1, 1001))

answer = 500
print(answer)
stdout.flush()
resp = input()

while resp != 'correct':
    
    if resp == 'lower':
        range = range[:answer]
    elif resp == 'higher':
        range = range[answer+1:]
    
    answer = range[len(range)//2]
    
    print(answer)
    stdout.flush()
    resp = input()