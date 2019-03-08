import sys
sys.stdin = open("password_input.txt")

T = int(input())
def fillgrid(grid, array):
    idx = 0
    for j in range(eachnum):
        grid[eachnum-j-1][j] = array[idx]
        idx +=1
    for j in range(eachnum):
        grid[j][eachnum+j+1] = array[idx]
        idx+=1
    for j in range(eachnum):
        grid[eachnum+j+1][len(grid)-j-1] = array[idx]
        idx += 1
    for j in range(eachnum):
        grid[len(grid)-1-j][eachnum-j-1] = array[idx]
        idx+=1

def getnumbers(grid):
    num1=""
    for j in range(eachnum):
        num1 += grid[eachnum-j-1][j]
    num2=""
    for j in range(eachnum):
        num2 += grid[j][eachnum+j+1]
    num3=""
    for j in range(eachnum):
        num3 += grid[len(grid)-j-1][eachnum+j+1]
    num4=""
    for j in range(eachnum):
        num4 += grid[eachnum+j+1][j]
    return num1, num2, num3, num4

def rotate(grid):
    
for tc in range(T):
    N, K = map(int, input().split())
    array = list(input())
    gridlength = N//2+1
    eachnum = N//4
    grid = [[None for _ in range(gridlength)] for _ in range(gridlength)]

    fillgrid(grid, array)
    print(*grid, sep="\n")
    print(getnumbers(grid))