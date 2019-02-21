from itertools import combinations
from copy import deepcopy
N, M = map(int, input().split())

grid = [list(map(int, input().split())) for _ in range(N)]

viruses = []
cartesians = {}
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def govirus(cat, elem, temp_min):
    global global_min
    temp_min += 1
    if temp_min > global_min: return
    poped = cat.pop(elem)
    for e in poped:
        if e in cat:
            govirus(cat, e, temp_min)

        


for r in range(N):
    for c in range(M):
        if grid[r][c] == 2:
            viruses.append((r,c))
            cartesians.update({(r,c):[]})
        elif grid[r][c] == 0:
            cartesians.update({(r,c):[]})
for cartesian in cartesians:
    for direction in directions:
        moved = tuple(map(sum, zip(cartesian, direction)))
        if -1 in moved or N == moved[0] or M == moved[1]:
            continue
        if grid[moved[0]][moved[1]] != 1:
            cartesians[cartesian].append(moved)
keylist = list(combinations(cartesians.keys()-viruses, 3))
global_max = 0
temp_min = 999
global_min = 999
while keylist:
    cat = deepcopy(cartesians)
    for cartesian in keylist.pop():
        cat.pop(cartesian)
    for virus in viruses:
        if virus in cat:
            govirus(cat, virus, temp_min)
    temp_max = len(cat)
    global_max = max(global_max, temp_max)
        
print(global_max)

