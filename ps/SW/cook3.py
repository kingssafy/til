import sys
sys.stdin = open("cook_input.txt")
result = 0;
total = 0;
N = 0;
select = [0] * 17


def dfs(k, selection, left): 
    if selection+left < int(N/2): return
    if k > N: return
    if k == N and selection == int(N/2): 
        global result;
        global total;
        tempa = 0;
        tempb = 0
        for y in range(N):
            for x in range(N):
                if select[y] and select[x]:
                    tempa += grid[y][x]
                if not select[y] and not select[x]:
                    tempb += grid[y][x]
        result = min(result, abs(tempa - tempb))
    else:
        select[k] = True;
        dfs(k+1, selection+1, left-1)
        select[k] = False;
        dfs(k+1, selection, left-1)




T = int(input())
for tc in range(T):
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]
    total = sum(sum(row) for row in grid)
    result = 9999999999
    dfs(0,0,N)
    print(result)



