import sys
sys.stdin = open("stair_input.txt")

def gettime(subset):
    
    for stair_idx in range(2):
        arrival_time = [0 for _ in range(5000)]
        for i in range(len(man)):
            if subset[i] == stair_idx:
                pass




def dfs(depth, subset):
    if depth == len(man):
        #TODO
        pass
    else:
        for i in range(2):
            subset[depth] = i
            dfs(depth+1, subset)



T = int(input())
for tc in range(T):
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]
    man = []
    stair = []
    for y in range(N):
        for x in range(N):
            if grid[y][x] == 1:
                man.append((y, x))
            elif grid[y][x] >= 2:
                stair.append((y,x))
    subset = [0 for _ in range(len(man))]
