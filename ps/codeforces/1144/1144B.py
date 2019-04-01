N = int(input())
arr = list(map(int, input().split()))
arr.sort()
flag = 1
before = N;
k = arr[-1]%2
odd = []
even = []
for a in arr:
    if a % 2:
        odd.append(a)
    else:
        even.append(a)

if len(odd) == len(even):
    print(0)
else:
    print(min(odd[0], even[0]))

