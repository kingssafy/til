import sys
sys.stdin = open("9067_input.txt")
T = int(input())

for tc in range(T):
    sy, sx = map(int, input().split())
    ey, ex = map(int, input().split())
    K = int(input())
    blocked = set()
    for _ in range(K):
        blocked.add(tuple(map(int, input().split())))
    
    print(blocked)
