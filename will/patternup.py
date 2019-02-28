M = int(input())
grid = [list(map(int, input())) for _ in range(M)]
P = int(input())
pattern = [list(map(int, input())) for _ in range(P)]
def rotateMatrix(mat): 
    N = len(mat)
    for x in range(0, int(N/2)): 
        for y in range(x, N-x-1): 
            temp = mat[x][y] 
            mat[x][y] = mat[y][N-1-x] 
            mat[y][N-1-x] = mat[N-1-x][N-1-y] 
            mat[N-1-x][N-1-y] = mat[N-1-y][x] 
            mat[N-1-y][x] = temp 
count = 0

for _ in range(4):
    rotateMatrix(pattern)
    for r in range(M-P):
        for c in range(M-P+1): 
            value = grid[r][c]
            flag = 1
            if value == 1 or value == 0:
                for x in range(P):
                    for y in range(P):
                        if grid[r+x][c+y] != pattern[x][y]:
                            flag =0
                            break
                    if flag ==0 :break
                else:
                    count += 1
if count:
    print(count)
else: 
    print(0)
