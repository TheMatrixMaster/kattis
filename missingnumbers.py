n = int(input())

nums = [0] * 200

for _ in range(n):
    nums[int(input())-1] = 1

c = 0

for i, num in enumerate(nums):
    if c == n: 
        if i == n:
            print('good job')
        break

    if num == 0:
        print(i+1)
    else:
        c += 1
    