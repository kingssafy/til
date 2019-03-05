import sys
sys.stdin = open("froggy_input.txt")

N = int(input())
lotus = [int(input()) for _ in range(N)]
lotus.sort()
count = 0
length = len(lotus)
last = lotus[-1]

def bs_up(s, e, d):
    m = -1
    sol = -1
    while s <= e:
        m = (s+e)//2
        if lotus[m] < d:
            sol = m +1
            s = sol
        else:
            e = m-1;
    return sol;

for first in range(length-2):
    f = lotus[first]
    for second in range(first+1, length-1):
        s = lotus[second]
        jump = s-f
        count += bs_up(second, length-1, s+2*jump+1) - bs_up(second, length-1,s+jump)

print(count)

