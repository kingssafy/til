f_row, f_col, f_len_row, f_len_col = map(int, input().split())
s_row, s_col, s_len_row, s_len_col = map(int, input().split())
grid = [[0 for _ in range(100)] for _ in range(100)]

for r in range(f_row, f_row + f_len_row):
    for c in range(f_col, f_col+f_len_row):
        grid[r][c] += 1

for r in range(s_row, s_row + s_len_row):
    for c in range(s_col, s_col+s_len_row):
        grid[r][c] += 2

print(*grid, sep="\n")
directions = [(1,0), (-1, 0), (0, 1), (0, -1), (1,1), (1,-1), (-1,1), (-1,-1)]
def configure(grid):
    count = 0
    if 3 in [item for row in grid for item in row]:
        return 3
    for x in range(100):
        for y in range(100):
            value = grid[x][y]
            if value == 1:
                for direction in directions:
                    next = tuple(map(sum, zip((x,y), direction)))
                    if next[0] >= 0 and next[1] >= 0 and next[0] <100 and next[1]<100:
                        nextvalue = grid[next[0]][next[1]]
                        if nextvalue == 2:
                            count += 1
                            print(count)
                            if count >1:
                                return 2
    if count == 1:
        return 1
    return 4
print(configure(grid))

