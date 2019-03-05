import sys
sys.stdin = open("hike_input.txt")

def isvalid(array, co):
    return 0<=co[0]<len(array) and 0<=co[1]<len(array)

def next(co, direction):
    return tuple(map(sum, zip(co, direction)))

def gohike(array, co, K, possible=True, before=9999, count=0):
    global result
    count +=1
    if isvalid(array, co):
        now = array[co[0]][co[1]]
        if now < before:
            after = now
            array[co[0]][co[1]] = 999
        elif now - K < before and possible:
            after = before - 1
            array[co[0]][co[1]] = 999
            possible = False
        else:
            return
        if count >= result:
            result = count
        for direction in directions:
            next_co = next(co, direction)
            gohike(array, next_co, K, possible, after, count)

        array[co[0]][co[1]] = now


for tc in range(int(input())):
    N, K = map(int, input().split()) # N은 지도한변, K는 최대공사가능깊이
    array = [list(map(int, input().split())) for _ in range(N)]
    maximum = 0
    starts = []
    directions = [(1,0), (0,1), (-1,0), (0,-1)]
    result = 0
    for row in array:
        maximum = max(max(row), maximum)
    for x in range(N):
        for y in range(N):
            if array[x][y] == maximum:
                starts.append((x,y))

    for start in starts:

        gohike(array, start, K, 1, 999999, 0)
    print("#{} {}".format(tc+1,result))