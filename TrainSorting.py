n = int(input())

arr = []

for i in range(n):
    arr.append(int(input()))

r = [[1, 1] for i in range(n)]
m = 0

for i in range(n-1, -1, -1):
    down = r[i+1:]

    for j in range(len(down)):
        [inc, dec] = down[j]

        if arr[i] < arr[i+j+1] and r[i][0] <= down[j][0]:
            r[i][0] = down[j][0] + 1

        elif arr[i] > arr[i+j+1] and r[i][1] <= down[j][1]:
            r[i][1] = down[j][1] + 1

    m = max(m, r[i][0] + r[i][1] - 1)


print(m)


# def go(p: [int], q: [int], ptr: int) -> int:
#     if ptr < len(q):
#         top = q[ptr]
#         if len(p) == 0:
#             return max(go([top], q, ptr+1), go([], q, ptr+1))
#         elif top < p[0]:
#             return max(go([top] + p, q, ptr+1), go(p, q, ptr+1))
#         elif top > p[-1]:
#             return max(go(p + [top], q, ptr+1), go(p, q, ptr+1))
#         else:
#             return go(p, q, ptr+1)
#     else:
#         return len(p)
#
#
# print(go([], arr, 0))

