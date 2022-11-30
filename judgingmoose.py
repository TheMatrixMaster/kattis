l, r = map(int, input().split(' '))
print(
    'Not a moose' if l==r==0 else
    f'Even {l+r}' if l==r else 
    f'Odd {2*max(l, r)}'
)