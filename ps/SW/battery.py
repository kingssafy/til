import sys
sys.stdin = open("battery_input.txt")

T = int(input())
nomove = (0,0)
up = (0, -1)
right = (1, 0)
down = (0, 1)
left = (-1, 0)
moves = {
        0:nomove,
        1:up,
        2:right,
        3:down,
        4:left,
        }
directions = [up, right, down, left]

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def isingrid(center):
    return 0<center[0]<=10 and 0<center[1]<=10
def isindistance(center, target, d):
    return (abs(center[0] - target[0]) + abs(center[1] - target[1])) <= d

for tc in range(1, T+1):
    M, N = map(int, input().split())  #time, #bc
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.insert(0,0)
    B.insert(0,0)
    result = 0 
    grid =[[[] for _ in range(11)] for _ in range(11)]
    starta = (1, 1)
    startb = (10,10)
    battery = []
    for i in range(N):
        x, y, d, p = map(int, input().split())
        center = x, y
        battery.append([])
        for r in range(1, 11):
            for c in range(1,11):
                target = (r, c)
                if isindistance(center, target, d):
                    grid[target[0]][target[1]].append([p, battery[i]])
                    grid[target[0]][target[1]].sort(reverse=True)
    time = 0
    while A:
        direction = moves[A.pop(0)]
        next = getnext(starta, direction)
        temp = grid[next[0]][next[1]]
        if tc == 1 : print(temp)
        if temp:
            if time not in temp[0][1]:
                result += temp[0][0]
                temp[0][1].append(time)
            elif time in temp[0][1] and len(temp) >= 2:
                result += temp[1][0]
        time +=1
        starta = next 

    time = 0
    while B:
        direction = moves[B.pop(0)]
        next = getnext(startb, direction)
        temp = grid[next[0]][next[1]]
        if tc == 1: print(temp, time)
        if temp:
            if time not in temp[0][1]:
                result += temp[0][0]
                temp[0][1].append(time+100)
            elif time in temp[0][1] and len(temp) >= 2:
                result += temp[1][0]
                temp[1][1].append(time+100)
        time +=1
        startb = next 
    
    print(result)
