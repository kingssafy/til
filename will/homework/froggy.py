import sys
sys.stdin = open("froggy_input.txt")

N = int(input())
lotus = [int(input()) for _ in range(N)]
lotus.sort()
count = 0
length = len(lotus)
last = lotus[-1]

def ok(array, i, target):
    return array[i] >= target

def bs(array, target):
    x = -1
    b = len(array)
    while b >= 1:
        while x+b < len(array) and (not ok(array, x+b, target)):
            x += b
        b //= 2
    return x +1

for first in range(length-2):
    f = lotus[first]
    for second in range(first+1, length-1):
        s = lotus[second]
        jump = s-f
        count += bs(lotus, s+2*jump+1) - bs(lotus, s+jump)


print(count)

