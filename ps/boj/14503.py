N, M = map(int, input().split())
r, c, d = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
directions = {0:(-1, 0), 1:(0,1), 2: (1, 0), 3:(0,-1)}

def isvalid(r, c):
    return r>=0 and c>=0 and r<N and c<M
def allblock(r, c):
    for value in directions.values():
        next_r = r+value[0]
        next_c = c+value[1]
        if isvalid(next_r, next_c) and grid[next_r][next_c] == 0:
            return False
    return True

def cleanup(r, c , d):
    global count
    if grid[r][c] == 0:
        count += 1
        grid[r][c] = -1 
    back = directions[(d-2)%4] 
    back_r = r+back[0]
    back_c = c+back[1]
    if allblock(r,c) and isvalid(back_r, back_c) and grid[back_r][back_c] != 1:
        cleanup(back_r, back_c, d)
        return
    elif allblock(r,c) and isvalid(back_r, back_c) and grid[back_r][back_c] == 1: 
        return
    for _ in range(4):
        d = (d-1)%4
        left = directions[d]
        move_r = r + left[0]
        move_c = c + left[1]
        if isvalid(move_r, move_c) and grid[move_r][move_c] == 0:
            cleanup(move_r, move_c, d)
            return
        elif isvalid(move_r, move_c) and grid[move_r][move_c] !=0 or not isvalid(move_r, move_c):
            continue



count = 0

def main():
    hack = 0
    cleanup(r,c, d)
    for row in grid:
        hack += row.count(-1) 
    print(count)
main()
