
N = int(input())
a = {i:0 for i in range(1, 6)}
b = {i:0 for i in range(1, 6)}
for x in map(int, input().split()):
    a[x] += 1
for x in map(int, input().split()):
    b[x] += 1

c = {n:v+value for n, v, value in zip(range(1, 6), a.values(), b.values()) }

for value in c.values():
    if value%2:
        print(-1)
        exit()
d = {n:abs(value/2-v) for n, v, value in zip(range(1, 6), a.values(), c.values()) }

result = 0
for value in d.values():
    if value:
        result = max(result, value);
print(int(result))
