import sys
sys.stdin = open("workshop_input.txt")

def BFS(start, adj):
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
    return level

for tc in range(1, 11):
    N, M = map(int, input().split())
    adj = {}
    for node in range(1, N+1):
        adj[node] = []
    arrays = list(map(int, input().split()))

    for i in range(int(len(arrays)//2)):
        start = 2*i
        end = 2*i+1
        if arrays[end] not in adj[arrays[start]]:
            adj[arrays[start]].append(arrays[end])
    result = BFS(M, adj)
    gmax = max(result.values())
    results = 0
    for key, value in result.items():
        if value == gmax and key > results:
            results = key
    print(f"#{tc} {results}")
    
    
