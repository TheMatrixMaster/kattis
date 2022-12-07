x, y = map(int, input().split(' '))

# any number of X junctions is fine since it has even degree of 4
# number of Y junctions must be even since Y has degree 3
# if we had only 1 Y junction, we could connect two of the three edges, but
# the last edge will be free

if y % 2 == 0:
    print("possible")
else:
    print("impossible")