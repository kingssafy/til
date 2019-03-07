import sys
sys.stdin = open("pinball_input.txt")
#Global vars
up = (-1, 0)
down = (1, 0)
right = (0, 1)
left = (0, -1)

directions ={
    up:right,
    right: down,
    down: left,
    left: up,
}
wormhole = {}


def iswall(center, N):
    return center[0] == -1 or center[1] == -1 or center[0] == N or center[1] == N

def wall(center, direction):
    return block5(center, direction)


def wormholegen(center, num):
    if num in wormhole:
        wormhole[wormhole[num]] = center
        wormhole[center] = wormhole[num]
        del wormhole[num]
    else:
        wormhole[num] = center
        wormhole[center] = num
def itswormhole(center, direction):
    if center in wormhole:
        next = wormhole[center]
        next = getnext(next, direction)
        return next, direction
    print("itswormholeerror")

#
def backward(direction):
    if direction in directions:
        return directions[directions[direction]]
    else:
        print("Backworderror")

def getnext(center, direction):
    return tuple(map(sum, zip(center, direction)))

def block1(center, direction):
    if direction == up or direction == right:
        return block5(center, direction)

    if direction == down:
        nextdirection = right
        next = getnext(center, nextdirection)
        return next, nextdirection
    if direction == left:
        nextdirection = up
        next = getnext(center, nextdirection)
        return next, nextdirection
    raise block1error

def block2(center, direction):
    if direction == right or direction == down:
        return block5(center, direction)

    if direction == up:
        nextdirection = right
        next = getnext(center, nextdirection)
        return next, nextdirection

    if direction == left:
        nextdirection = down
        next = getnext(center, nextdirection)
        return next, nextdirection
    raise block2error

def block3(center, direction):
    if direction == down or direction == left:
        return block5(center, direction)

    if direction == right:
        nextdirection = down
        next = getnext(center, nextdirection)
        return next, nextdirection

    if direction == up:
        nextdirection = left
        next = getnext(center, nextdirection)
        return next, nextdirection
    raise block3error

def block4(center, direction):
    if direction == up or direction == left:
        return block5(center, direction)
    if direction == right:
        nextdirection = up
        next = getnext(center, nextdirection)
        return next, nextdirection

    if direction == down:
        nextdirection = left
        next = getnext(center, nextdirection)
        return next, nextdirection
    raise block4error


def block5(center, direction):
    if direction in directions:
        nextdirection = backward(direction)
        next = getnext(center, nextdirection)
        return next, nextdirection
    raise block5error

def main():
    T = int(input())
    pinball = {}

    for tc in range(1, T+1):
        end = []
        N = int(input())
        for r in range(N):
            for c, value in enumerate(list(map(int ,input().split()))):
                center = (r, c)
                if value == 0: continue
                if value == 1:
                    pinball[center] = block1
                elif value == 2:
                    pinball[center] = block2
                elif value == 3:
                    pinball[center] = block3
                elif value == 4:
                    pinball[center] = block4
                elif value == 5:
                    pinball[center] = block5
                elif 6 <= value <= 10:
                    wormholegen(center, value)
                    pinball[center] = itswormhole
                elif value == -1:
                    end.append((r, c))
        maxcount = 0
        for x in range(N):
            for y in range(N):
                if (x, y) in pinball or (x, y) in wormhole or (x, y) in end: continue
                for direction in directions:
                    center = (x,y)
                    start = center
                    active = 1
                    count = 0
                    next = center
                    first = 1
                    while active:
                        if next in end:
                            active = 0
                            break
                        if next == start and not first:
                            active = 0
                            break
                        first = 0
                        if iswall(next, N):
                            next, direction = wall(next, direction)
                            count += 1
                            continue
                        if next not in pinball:
                            next = getnext(next, direction)
                            continue
                        if next in pinball and pinball[next] != itswormhole:
                            next, direction = pinball[next](next, direction)
                            count += 1
                            continue
                        if next in pinball and pinball[next] == itswormhole:
                            next, direction = pinball[next](next, direction)
                            continue

                    maxcount = max(maxcount, count)
        print(maxcount)

        wormhole.clear()
        pinball.clear()

main()