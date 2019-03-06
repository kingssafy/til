import sys
sys.stdin = open("doughnut_input.txt")

def doughnut(grid, center, K):
    result = 0
    for k in range(K):
        step = None if k == K-1 or k == 0 else K-1
        result += sum(grid[center[0]+k][center[1]:center[1]+K:step])
    return result
    


N, K = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
maximum = 0
for x in range(N-K+1):
    for y in range(N-K+1):
        maximum = max(maximum, doughnut(grid, (x,y), K))
print(maximum)
