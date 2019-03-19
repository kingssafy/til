N = int(input()) #width of square grid

start = tuple(map(int, input().split()))
end = tuple(map(int, input().split()))
grid = [list(map(int, input())) for _ in range(N)]
directions = [(1,0), (-1,0), (0,1), (0,-1)]
start = tuple(map(sum, zip(start, (-1,-1))))
end = tuple(map(sum, zip(end, (-1,-1))))
starts = []
ends = []
frontier = [start]
while frontier:
    next = []
    for u in frontier:
        if u not in starts:
            starts.append(u)
            for direction in directions:
                du = tuple(map(sum, zip(u, direction)))
                if du in starts: 
                    continue
                if du[0] >=0 and du[1] >=0 and du[0] < N and du[1] < N:
                    value = grid[du[0]][du[1]]
                    if value == 0:
                        next.append(du)
    frontier=next
frontier = [end]
while frontier:
    next = []
    for u in frontier:
        if u not in ends:
            ends.append(u)
            for direction in directions:
                du = tuple(map(sum, zip(u, direction)))
                if du in ends: 
                    continue
                if du[0] >=0 and du[1] >=0 and du[0] < N and du[1] < N:
                    value = grid[du[0]][du[1]]
                    if value == 0:
                        next.append(du)
    frontier=next
min =9999
for u in starts:
    for v in ends:
        value = (u[0] - v[0])**2 + (u[1] - v[1])**2
        if value < min:
            min = value

print(min)
