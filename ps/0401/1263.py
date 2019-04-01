import sys
sys.stdin = open("1263_input.txt")
sys.stdout = open("1263_output.txt", "w")
T = int(input())
for tc in range(T):
    raw = list(map(int, input().split()))
    N = raw[0]
    adj = []
    a = 1
    distance = [[0 for _ in range(N)] for _ in range(N)]
    for _ in range(N):
        adj.append(raw[a:a+N])
        a += N
    for i in range(N):
        for j in range(N):
            if i == j:
                distance[i][j] = 0
            elif adj[i][j]:
                distance[i][j] = adj[i][j]
            else:
                distance[i][j] = 9999
    for i in range(N):
        for j in range(N):
            for k in range(N):
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j])
    print(f"#{tc+1}", min(sum(row) for row in distance))
