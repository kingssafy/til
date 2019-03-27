import sys
sys.stdin = open("cook_input.txt")
mini = 999999
def dfs(s=0):
    global mini
    if sum(visit) == N/2:
        temp = 0;
        for i in range(N):
            for j in range(N):
                if visit[i] and visit[j]:
                    temp += grid[i][j];
        mini = min(mini, total-2*temp);

    else:
        for i in range(s, N):
            if not visit[i]:
                visit[i] = 1;
                dfs(s+1)
                visit[i] = 0;
                dfs(s+1);








T = int(input())
for tc in range(T):
    N = int(input())
    grid = [list(map(int, input().split())) for _ in range(N)]
    total = sum(sum(row) for row in grid)
    visit = [0]*20
    mini = 99999999999
    dfs(0)
    print(mini)
     
