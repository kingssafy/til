M = int(input())
grid = [list(map(int, input())) for _ in range(M)]
print(*grid,sep="\n")
P = int(input())
pattern = [list(map(int, input())) for _ in range(P)]
count = 0
for r in range(M-P):
    for c in range(M-P+1): 
        value = grid[r][c]
        flag = 1
        if value == 1:
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
