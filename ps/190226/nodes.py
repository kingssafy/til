import sys
sys.stdin = open("nodes_input.txt")

def BFS(start, end, adj):
    level = {start:0}
    parent = {start:None}
    i = 1
    frontier = [start]
    while frontier:
        next = []
        for u in frontier:
            for v in adj[u]:
                if v not in level:
                    level[v] = i
                    parent[v] = u
                    next.append(v)
        frontier = next
        i += 1
    if end in level:
        return level[end]
    else:
        return 0

for tc in range(int(input())):
    V, E = map(int, input().split())
    adj = {}
    for i in range(1, V+1): adj[i] = []
    for _ in range(E):
        start, end = map(int, input().split())
        adj[start].append(end)
        adj[end].append(start)
    start, end = map(int, input().split())
    print(f"#{tc+1} {BFS(start, end, adj)}")
