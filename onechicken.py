n, m = map(int, input().split(' '))
l = m-n if m > n else n-m
suffix = 's' if l > 1 else ''

if n < m:
    print(f'Dr. Chaz will have {l} piece{suffix} of chicken left over!')
else:
    print(f'Dr. Chaz needs {l} more piece{suffix} of chicken!')