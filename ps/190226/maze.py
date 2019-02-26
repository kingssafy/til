import sys
sys.stdin = open("maze_input.txt")

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
        i+= 1
    if end in level:
        return level[end] - 1
    else:
        return 0

for tc in range(int(input())):
    N = int(input())
    grid = [list(map(int, input())) for _ in range(N)]
    adj = {}
    directions = [(0,1), (0, -1), (1, 0), (-1, 0)]
    for x in range(N):
        for y in range(N):
            if grid[x][y] != 1:
                adj[(x, y)] = []
            if grid[x][y] == 2:
                start = (x,y)
            if grid[x][y] == 3:
                end = (x,y)

    for x, y in adj:
        for direction in directions:
            dx = x + direction[0]
            dy = y + direction[1]
            if dx >= 0 and dy >= 0 and dx < N and dy < N:
                if grid[dx][dy] != 1:
                    adj[(x,y)].append((dx,dy))
    print(f"#{tc+1} {BFS(start, end, adj)}")
