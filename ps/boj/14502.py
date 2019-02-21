from itertools import combinations
N, M = map(int, input().split())



grid = [list(map(int, input().split())) for _ in range(N)]

viruses = []
cartesians = {}
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def govirus(cat, elem):
    global temp_max
    poped = cat.pop(elem)
    for e in poped:
        if e in cat:
            govirus(cat, e)

def recurse(selects):
    selects += 1
    if selects == 3:
        cat = deepcopy(cartesians)
        temp_max = 0
        for select in selected:
            if select in cat:
                cat.pop(select)
        for virus in viruses:
            if virus in cat:
                govirus(cat, virus)
                
        global globalmax
        globalmax = max(globalmax, len(cat))
        return
    for idx, cartesian in enumerate(keylist):
        if cartesian in viruses: continue
        if not idx in selected[:selects]:
            selected[selects] = idx
            recurse(selects)
        


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
keylist = list(cartesians.keys())
selected = [-1]*len(cartesians)
globalmax = 000
temp_max = 0
selects = -1
recurse(selects)
print(globalmax)
