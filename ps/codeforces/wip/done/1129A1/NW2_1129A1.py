n, m = map(int, input().split())
count, length = {}, {}
for _ in range(m):
    a, b = map(int, input().split())
    count[a] = count[a]+1 if a in count.keys() else 1
    length[a] = min(length[a], (b+n-a) % n) if a in length else (b+n-a) % n
for i in range(1, n+1):
    print(
    list(length[j] + j-i + n*(count[j]-(i <= j)) for j in count
    ), sep = ", ")
    print()
