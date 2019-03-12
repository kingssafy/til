a = [-1, 2, 4, -3, 5, 2, -5, 2, -99, 5]


best = 0
sum = 0

print(a)
for i in range(len(a)):
    print("sum", "= max(", a[i], ",", sum+a[i], ")")
    sum = max(a[i], sum+a[i])
    best = max(best, sum)

print(best)
