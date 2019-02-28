N = int(input())
array = [[0 for _ in range(100)] for _ in range(100)]

for _ in range(N):
    r, c = map(int, input().split())
    for x in range(r, r+10):
        for y in range(c, c+10):
            array[x][y] += 1

count = 0
for row in array:
    count += row.count(0)

column = 0
directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
for x in range(100):
    for y in range(100):
        if not array[x][y]:
            for direction in directions:
                next = tuple(map(sum, zip((x,y), direction)))
                if next[0] >= 0 and next[1] >=0 and next[0] < 100 and next[1]< 100:
                    if array[next[0]][next[1]]:
                        column += 1
        elif array[x][y] and (x == 99 or y == 99 or x == 0 or y == 0):
            column+= 1
            if x == y or x+y == 99:
                column+=1
print(column)

