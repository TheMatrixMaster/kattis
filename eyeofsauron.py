s = list(str(input()))

if len(s) % 2 == 1:
    print('fix')
elif s[len(s)//2 - 1] != '(':
    print('fix')
elif s[len(s)//2] != ')':
    print('fix')
else:
    print('correct')
