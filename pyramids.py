n = int(input())

height = 0
side_length = 1

while n >= (side_length**2):
    n -= (side_length**2)
    
    height += 1
    side_length += 2

print(height)