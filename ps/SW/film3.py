import sys
sys.stdin = open("film_input.txt")
result = 0;
def dfs(drugs, depth, chm_count, prev_count, prev_maxcount):
    global result
    if chm_count > K:return

    if depth == Y:
        for x in range(X):
            if prev_maxcount[x] < K:
                return
        else:
            result = min(result, chm_count);            
    else:
        cur_count = [1 for a in max_count]
        cur_maxcount = [1 for a in max_count]
        for i in range(3):
            drugs[depth] = i
            prev_row = [grid[depth-1][x] if drugs[i-1] == 2 else drugs[i-1] for x in range(X)]
            cur_row =  [grid[depth][x] if drugs[i] == 2 else drugs[i] for x in range(X)]
            for x in range(X):
                if prev_row[x] == cur_row[x]:
                    cur_count[x] = prev_count[x] + 1
            for x in range(X):
                cur_maxcount[x] = max(cur_count[x], prev_maxcount[x])
            dfs(drugs, depth+1, chm_count + (1 if i != 2 else 0), cur_count, cur_maxcount)



T = int(input())

for tc in range(T):
    Y, X, K = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(Y)]
    drugs = [2 for _ in range(Y)] 
    max_count = [1 for _ in range(X)]
    prev_count = [1 for _ in range(X)]
    result = 1e9;
    drugs[0] = 2
    dfs(drugs, 1, 0, prev_count, max_count)
    drugs[0] = 1
    dfs(drugs, 1, 1, prev_count, max_count)
    drugs[0] = 0
    dfs(drugs, 1, 1, prev_count, max_count)
    print(result)
