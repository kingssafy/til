import sys
sys.stdin = open("cafe_input.txt")


#directions = {
#        "rb": (1, 1),
#        "lb": (1, -1),
#        "lt": (-1, -1),
#        "rt": (-1, 1),
#        } # rb lb lt rt

directions = [(1, 1), (1, -1), (-1, -1), (-1, 1)]
def getnext(start, direction):
    return tuple(map(sum, zip(start, direction)))

def isvalid(grid, cartesian):
    return 0<=cartesian[0]< len(grid) and 0 <= cartesian[1] < len(grid[0])

def isnodouble(grid, next, nodouble):
    return grid[next[0]][next[1]] not in nodouble 
    

def cafe(grid, start):
    di = 0
    ate = []
    value = grid[start[0]][start[1]]
    ate.append(value)
    frontier = [(start, ate, di)]
    while frontier:
        next = []
        for complex in frontier:
            now = complex[0]
            di = complex[2]
            for idx, direction in enumerate(directions[di:di+2]):
                ate = complex[1].copy() #copy T^T
                jump = getnext(now, direction) 
                if isvalid(grid, jump) and isnodouble(grid, jump, ate):
                    ate.append(grid[jump[0]][jump[1]])
                    next.append((jump, ate, di+idx))
                elif jump == start:
                    global maximum
                    if len(ate)  > maximum:
                        maximum = len(ate) 
        frontier = next

for tc in range(int(input())):
    N = int(input()) # length of Row and Column wise
    grid = [list(map(int, input().split())) for _ in range(N)]
    maximum = 0

    for r in range(N):
        for c in range(N):
            if isvalid(grid, (r,c)):
                cafe(grid, (r,c))
    if not maximum: maximum=-1
    print("#{} {}".format(tc+1, maximum))

