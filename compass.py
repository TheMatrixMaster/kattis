n1 = int(input())
n2 = int(input())

clw = (n2-n1)%360

if clw > 180:
    clw -= 360

print(clw)