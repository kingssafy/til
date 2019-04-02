import sys
sys.stdin = open("5247_input.txt")

def minimum(a, b):
    Q = []
    front = 0
    Q.append((a, 0))
    while (front < len(Q)):
        a = Q[front][0]
        n = Q[front][1]
        front += 1;
        if a == b:
            return n
        if a+1 <= 1000000 and not visit[a+1]: 
            visit[a+1] = 1;
            Q.append((a+1, n+1)) 
        if a-1 <= 1000000 and not visit[a-1]:
            visit[a-1] = 1;
            Q.append((a-1, n+1))
        if a*2 <= 1000000 and not visit[a*2] :
            visit[a*2] = 1
            Q.append((a*2, n+1))
        if a-10 <= 1000000 and not visit[a-10]:
            visit[a-10] = 1
            Q.append((a-10, n+1))
    return -1

T = int(input())
for tc in range(T):
    a, b = map(int, input().split())
    visit = [0 for _ in range(1000001)]
    print(f"#{tc+1}", minimum(a,b))
