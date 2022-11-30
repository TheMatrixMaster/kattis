measurements = {
    'th': 1.0,
    'in': 1000.0,
    'ft': 12.0,
    'yd': 3.0,
    'ch': 22.0,
    'fur': 10.0,
    'mi': 8.0,
    'lea': 3.0
}

convert = {
    'thou': 'th',
    'inch': 'in',
    'foot': 'ft',
    'yard': 'yd',
    'chain': "ch",
    'furlong': 'fur',
    'mile': 'mi',
    'league': 'lea'
}

keys = list(measurements.keys())

n, u1, _, u2 = input().split(' ')

u1 = convert[u1] if u1 in convert else u1
u2 = convert[u2] if u2 in convert else u2

if u1 == u2: 
    print(n)
else:
    k1 = keys.index(u1)
    k2 = keys.index(u2)

    acc=float(n)

    if k1 > k2:
        for k in keys[k2+1:k1+1]:
            acc = acc * measurements[k]
    
    else:
        for k in keys[k1+1:k2+1]:
            acc = acc / measurements[k]

    print(acc)
