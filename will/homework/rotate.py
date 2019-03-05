def rotateMatrix(mat): 
    N = len(mat)
    for x in range(0, int(N/2)):  #level
        for y in range(x, N-x-1): # last = N-1
            temp = mat[x][y] 
            mat[x][y] = mat[y][N-1-x] 
            mat[y][N-1-x] = mat[N-1-x][N-1-y] 
            mat[N-1-x][N-1-y] = mat[N-1-y][x] 
            mat[N-1-y][x] = temp 
n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

degree = int(input())
while degree:
    for i in range((-int(degree/90))%4):
        rotateMatrix(grid)
    for row in grid:
        print(*row)
    degree=int(input())
