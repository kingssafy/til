import sys
sys.stdin = open("runner_input.txt")
sys.stdout = open("runner_output.txt", "w")


directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
def getdirections(*args):
    result = []
    for arg in args:
        result.append(directions[arg])
    return result
tunnels = {
        1:getdirections(0,1,2,3),
        2:getdirections(0,1),
        3:getdirections(2,3),
        4:getdirections(1,2),
        5:getdirections(0,2),
        6:getdirections(0,3),
        7:getdirections(1,3),
        }
go = {
        1:getdirections(0,1,2,3),
        2:getdirections(0,1),
        3:getdirections(2,3),
        4:getdirections(0,3),
        5:getdirections(1,3),
        6:getdirections(1,2),
        7:getdirections(0,2),
        }
def isvalid(array, now, direction):
    if 0 <= now[0] <len(array) and 0 <= now[1] <len(array[0]):
        pipe = array[now[0]][now[1]]
        if pipe:
            return direction in tunnels[pipe]
    return False

def isdirectionvalid(array, now, direction): 
    if 0 <= now[0] <len(array) and 0 <= now[1] <len(array[0]):
        pipe = array[now[0]][now[1]]
        if pipe: 
            return direction in go[pipe]
            
    return False

        

def run(array, start):
    level = 1
    frontier = []
    hours[start] = 1
    for direction in directions:
        jump= tuple(map(sum, zip(start, direction)))
        if isdirectionvalid(array, start, direction) and isvalid(array, jump, direction) and array[jump[0]][jump[1]]:
            frontier.append(jump)

    while frontier:
        level += 1
        next = []
        for i in frontier:
            if i not in hours:
                hours[i] = level
                for direction in directions:
                    jump = tuple(map(sum, zip(i, direction)))
                    if isdirectionvalid(array, i, direction) and isvalid(array, jump, direction) and array[jump[0]][jump[1]]:
                        next.append(jump) 
        frontier = next
                

for tc in range(int(input())):
    N, M, R, C, L = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]
    hours = {}
    run(grid,(R,C))
    counts = 0
    for key, value in hours.items():
        if value <= L:
            counts += 1

    print(f"#{tc+1} {counts}")
