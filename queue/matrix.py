import sys
sys.stdin = open("matrix_input.txt")

def makezero(stacks):
    global grid
    start = stacks[-2]
    end = stacks[-1]
    for x in range(start[0], end[0]+1):
        for y in range(start[1], end[1]+1):
            grid[x][y] = 0

for tc in range(int(input())):
    n = int(input())
    grid = [list(map(int, input().split())) for _ in range(n)]
    stacks= []
    inmatrix = 0
    for x in range(n):
        for y in range(n):
            value = grid[x][y]
            if value != 0 and not inmatrix:
                stacks.append((x,y))
                inmatrix = 1
            elif value == 0 and inmatrix:
                y-=1
                for j in range(x+1, n):
                    value = grid[j][y]
                    if value == 0:
                        stacks.append((j-1,y))
                        makezero(stacks)
                        inmatrix = 0
                        break
                else:
                    stacks.append((n-1,y))
                    makezero(stacks)
                    inmatrix=0
        else:
            if inmatrix:
                for j in range(x, n):
                    value = grid[j][y]
                    if value == 0:
                        stacks.append((j-1,y))
                        makezero(stacks)
                        inmatrix = 0
                        break
                else:
                    stacks.append((n-1,y))
                    makezero(stacks)
                    inmatrix=0

    result = []
    for i in range(len(stacks)//2):
        result.append((stacks[2*i+1][0] - stacks[2*i][0] + 1,stacks[2*i+1][1] - stacks[2*i][1] + 1))
    result.sort()
    click = [item for items in result for item in items]
    print(f"#{tc+1}", len(result), *click)

