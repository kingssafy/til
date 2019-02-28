def root_calc(num):
    while True:
        temp = map(int, str(num))
        tot = sum(temp)
        if tot < 10: return tot
        num = tot

root_max = 0
sol = 0
for i in range(N):
    root = root_calc(arr[i])
    if root_max < root:
        root_max = root
        sol = arr[i]

    if root_max == root:
        if sol > arr[i]:
            sol = arr[i]
print(sol)
