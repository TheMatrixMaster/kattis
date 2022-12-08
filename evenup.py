n = int(input())

nums = list(map(int, input().split(' ')))
stack = []

for num in nums:
    if not stack: stack.append(num)
    else:
        top = stack[-1]
        if (top + num) % 2 == 0:
            stack.pop()
        else:
            stack.append(num)
            
            
print(len(stack))