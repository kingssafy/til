import sys
sys.stdin = open("snake_input.txt")
N = int(input()) # # tiles
K = int(input()) # # fruits
fruits = []
snack = [(1,1)]
directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
right = dict(zip(directions, directions[1:]+directions[:1]))
left = {value: key for key,value in right.items()}
for _ in range(K):
    fruits.append(tuple(map(int, input().split())))

L = int(input())
go = {}
for _ in range(L):
    X, C = input().split()
    X = int(X)
    go[X]=C
print(go)
sec = 0
direction = (0, 1)
active = 1
while True:
    sec += 1
    snack.append(tuple(map(sum, zip(snack[-1], direction))))
    if snack[-1] in snack[:-1]:
        active = 0
        break
    if snack[-1][0] == 0 or snack[-1][1] == 0 or snack[-1][1] > N or snack[-1][0] > N:
        active = 0
        break
    if snack[-1] in fruits:
        fruits.pop(fruits.index(snack[-1]))
    else:  
        snack.pop(0)
    if sec in go:
        C = go[sec]
        if C == "D":
            direction = right[direction]
        elif C== "L":
            direction = left[direction]
print(sec)
