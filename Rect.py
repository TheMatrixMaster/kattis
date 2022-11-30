raw = str(input()).strip().split(' ')

p = (float(raw[0]), float(raw[1]))
q = (float(raw[2]), float(raw[3]))

area = abs(p[0] - q[0]) * abs(p[1] - q[1])

print("%.3f" % area)