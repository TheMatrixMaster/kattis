import math
from sys import stdin

raw = str(input()).split(' ')

gop = (float(raw[0]), float(raw[1]))
dog = (float(raw[2]), float(raw[3]))

solved = False
# hole = str(input())

lines = stdin.read().splitlines()

for hole in lines:
    if not hole:
        break

    p_hole = hole.strip().split(' ')
    p_hole = (float(p_hole[0]), float(p_hole[1]))

    d_gop = math.sqrt((p_hole[0] - gop[0]) ** 2 + (p_hole[1] - gop[1]) ** 2)
    d_dog = math.sqrt((p_hole[0] - dog[0]) ** 2 + (p_hole[1] - dog[1]) ** 2)

    if d_gop <= (d_dog / 2):
        print("The gopher can escape through the hole at (%.3f,%.3f)." % (p_hole[0], p_hole[1]))
        solved = True
        break

    # hole = str(input())

if not solved:
    print("The gopher cannot escape.")