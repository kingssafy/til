N, L = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(N) ]
rarray = [[array[x][y] for x in range(N)] for y in range(N)]
success = 0

for row in array+rarray:
    now = row[0]
    up_count = 0
    down_count = 0
    for step in row:
        if now == step:
            up_count += 1
            down_count += 1
        elif step == now + 1 and down_count >=0 and up_count >= L:
            now = step
            up_count = 1
        elif step + 1 == now and down_count >=0:
            now = step
            up_count = -L + 1
            down_count = -L + 1
        else:
            break
    else: 
        if down_count >= 0:
            success += 1

print(success)
