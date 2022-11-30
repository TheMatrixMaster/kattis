import math

h, v = map(int, input().split(' '))

if __name__ == '__main__':
    
    print(math.ceil(h/math.sin(v*math.pi/180)))