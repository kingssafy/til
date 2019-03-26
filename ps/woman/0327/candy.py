N = int(input())
array = list(map(int, input().split()))
array.sort();
result = array[-1]
for i in range(N-1):
    result += (N-i-1)* array[i]
print(result)
