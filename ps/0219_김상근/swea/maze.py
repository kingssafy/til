import sys
sys.stdin = open('maze_input.txt')

def recurse(key):
    global goal
    if goal ==1 : return
    while adjacent[key]:
        next = adjacent[key].pop()
        if next == end:
            goal = 1
            return True
        recurse(next)

directions = [(1,0), (-1,0), (0,-1), (0, 1)]
for tc in range(int(input())):
    n = int(input())
    mazes = [[int(char) for char in input()] for _ in range(n)]
    adjacent = {}
    for x in range(n):
        for y in range(n):
            value = mazes[x][y]
            if value == 2:
                start = (x, y)
                adjacent.update({start:[]})
            if value == 3:
                end = (x, y)
                adjacent.update({end:[]})
            if value == 0: adjacent.update({(x,y):[]})
    for key in adjacent:
        for direction in directions:
            x, y = map(sum, zip(key, direction))
            if x < 0 or y < 0 or x >= n or y>=n: 
                pass
            else:
                if mazes[x][y] != 1: adjacent[key].append((x, y))
    goal = 0
    recurse(start)
    print(f"#{tc+1} {goal}")
