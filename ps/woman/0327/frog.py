N = int(input())
array = []
for _ in range(N):
    array.append(int(input()))
    
array.sort()

def get(target):
    low = 0;
    high = len(array)
    while low < high:
        mid = (low+high)//2
        if array[mid] >= target:
            high = mid
        else:
            low = mid+1

    return high;


result = 0;
for i in range(len(array)-1):
    for j in range(i+1, len(array)):
        jump = array[j] - array[i]
        result += get(array[j]+jump*2+1) - get(array[j]+jump)

print(result)
        
