import sys
sys.stdin = open("longest.txt")
T = int(input())
def dfs(adj, start, N):
    global result
    visit = [0]*(N+1)
    visit[start] = 1;
    stack = [(start, 1)]
    while stack:
        now, l = stack.pop()
        result = max(result, l)
        for next in adj[now]:
            if visit[next]: continue
            visit[next] = 1;
            stack.append((next, l+1))

for tc in range(T):
    N, M = map(int, input().split())
    adj = {key:[] for key in range(1, 1+N)}
    for _ in range(M):
        f, t = map(int, input().split())
        adj[f].append(t)
        adj[t].append(f)
    result = 0
    for start in range(1, N+1):
        dfs(adj, start, N)
    print(f"#{tc+1} {result}")
