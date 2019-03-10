import sys
sys.stdin = open("battery_input.txt")

T = int(input())
nomove = (0,0)
up = (-1, 0)
right = (0, 1)
down = (1, 0)
left = (0, -1)
numtomove = {
        0:nomove,
        1:up,
        2:right,
        3:down,
        4:left,
        }
def getdistance(a, b):
    return abs(a[0]-b[0])+ abs(a[1]-b[1])

def getchargers(center):
    result = []
    for charger in chargers:
        if getdistance(center, charger["center"]) <= charger["distance"]:
            result.append(charger)
    return result

def maxcharge(a, b):
    a = getchargers(a)
    b = getchargers(b)
    if a and not b:
        _max = 0
        for charger in a:
            if charger["power"] >= _max:
                _max = charger["power"]
        return _max
    if b and not a:
        _max = 0
        for charger in b:
            if charger["power"] >= _max:
                _max = charger["power"]
        return _max
    if a and b:
        _max = 0
        for a_charger in a:
            for b_charger in b:
                if a_charger == b_charger:
                    temp = a_charger["power"]
                else:
                    temp = a_charger["power"] + b_charger["power"]

                if temp > _max:
                    _max = temp
        return _max

    else:
        return 0

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

for tc in range(1, T+1):
    M, num_charger = map(int, input().split())
    A_moves = list(map(int, input().split()))
    B_moves = list(map(int, input().split()))
    A_moves.insert(0,0)
    B_moves.insert(0,0)
    A = (1,1)
    B = (10, 10)
    chargers = []
    for key in range(num_charger):
        y, x, distance, power =map(int, input().split())
        chargers.append({"center":(x,y),
            "distance":distance,
            "power":power,
            "key":key})
    result = 0
    for _ in range(M+1):
        A = getnext(A, numtomove[A_moves.pop(0)])
        B = getnext(B, numtomove[B_moves.pop(0)])
        result += maxcharge(A, B)
    print(f"#{tc} {result}")
