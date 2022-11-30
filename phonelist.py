t = int(input())

for _ in range(t):
    n = int(input())
    nums = sorted([input() for _ in range(n)])
    
    consistent = True
        
    for i in range(0, len(nums)-1):
        if nums[i+1].startswith(nums[i]):
            consistent = False
            break
        
    if consistent: print('YES')
    else: print('NO')