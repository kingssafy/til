from heapq import heappush, heappop, heapify
N = int(input())
result = 0;
array = list(map(int, input().split()))
heapify(array)
while len(array) > 1:
    b = heappop(array)
    c = heappop(array)
    temp = b+c
    heappush(array, temp)
    result += temp

print(result)
