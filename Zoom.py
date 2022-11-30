raw = str(input()).split(' ')

n, gap = int(raw[0]), int(raw[1])
l = str(input()).split(' ')

out = l[gap-1::gap]

print(" ".join(out))