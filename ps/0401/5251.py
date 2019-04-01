import sys
sys.stdin = open("5251_input.txt")
from heapq import heapify, heappush, heappop
T = int(input())

for tc in range(T):
    N, E = map(int, input().split())
    adj = [list() for _ in range(N+1)]
    for _ in range(E):
        s, e, w = map(int, input().split())
        adj[s].append((e, w))
    distance = [10000 for _ in range(N+1)]
    distance[0] = 0;
    heapq = []
    heappush(heapq, (0,0))
    visit = [0]*(N+1)
    while heapq:
        a = heappop(heapq)[1]
        if visit[a]: continue;
        visit[a] = True;
        for b, w in adj[a]:
            if distance[b] > distance[a] + w:
                distance[b] = distance[a] +w
                heappush(heapq, (-distance[b], b))
    print(f"#{tc+1} {distance[-1]}")
