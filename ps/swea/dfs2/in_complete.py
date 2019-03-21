import sys
sys.stdin = open("in.txt", "r")

T = int(input())

for tc in range(T):
    N, M = map(int, input().split())
    t = {}
    for _ in range(N): t[int(input())] = 0 
    c = s = 0
    while c < M:
        s += 1
        for m in t:
            if s%m == 0:
                c += 1;
    print(f"#{tc +1} {s}")
