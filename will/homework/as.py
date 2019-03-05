import sys
sys.stdin = open("froggy_input.txt")
N = int(input())
lotus = [int(input()) for _ in range(N)]
lotus.sort()
count = 0
length = len(lotus)
last = lotus[-1]

def bisect(a, x, lo=0, hi=None):
    if lo < 0:
        return False
    if hi is None:
        hi = len(a)
    while lo < hi:
        mid = (lo + hi) //2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo
def bisect_leftmost(a, x, lo=0, hi=None):
    result = bisect(a, x, lo, hi)
    if a[result] == x:
        return result
    else:
        return result+1
def bisect_right(a, x, lo=0, hi=None):
    result = bisect(a, x, lo, hi)
    if a[result-1] == x:
        return result+1
    else:
        return result

for first in range(length-2):
    f = lotus[first]
    for second in range(first+1, length-1):
        s = lotus[second]
        if s - f > last - s: break
        goes = bisect_leftmost(lotus, 2*s-f)
        ends = bisect_right(lotus, s+2*(s-f))
        count += ends-goes+1
print(count)
