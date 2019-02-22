from itertools import combinations
from copy import deepcopy
N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

viruses = []
cartesians = []
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
directions2 = directions + [(1,1),(1,-1),(-1,1),(-1,-1)]

        


for r in range(N):
    for c in range(M):
        if grid[r][c] == 2:
            viruses.append((r,c))
        elif grid[r][c] == 0:
            cartesians.append((r,c))
keylist = list(combinations(cartesians, 3))
infected = []
global_max = 999
result = 0
for walls in keylist:
    infected.clear()
    temp_max = 0
    for wall in walls:
        wall_count = 0
        for direction in directions2:
            if wall_count != 0: break
            moved = tuple(map(sum, zip(wall, direction)))
            if -1 in moved or N == moved[0] or M == moved[1]:
                continue
            moved_value = grid[moved[0]][moved[1]]
            if moved_value == 1 or moved in walls:
                wall_count += 1
                break

    if wall_count == 0:
        continue

    for virus in viruses:
        infected.append(virus)
        temp_max += 1 
    for infect in infected:
        if temp_max >= global_max : break
        for direction in directions:
            moved = tuple(map(sum, zip(infect, direction)))
            if -1 in moved or N == moved[0] or M == moved[1]:
                continue
            moved_value = grid[moved[0]][moved[1]] 
            if moved_value != 1 and moved not in infected and moved not in walls:
                infected.append(moved)
                temp_max += 1
                if temp_max >= global_max : break
                
    if temp_max < global_max:
        global_max = temp_max
        
print(N*M-sum(row.count(1) for row in grid)-global_max-3)
