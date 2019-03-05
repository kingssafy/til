import sys
sys.stdin = open("bingo_input.txt")
boards = [list(map(int, input().split())) for _ in range(5)]
answers = [list(map(int, input().split())) for _ in range(5)]

def result(boards):
    bingo = 0
    for board in boards:
        if sum(board) == 0 : bingo+=1
    rotate = [[row[idx] for row in boards] for idx in range(5)]

    for board in rotate:
        if sum(board) == 0 : bingo+=1
    a = []
    b = []
    for x, y in zip(range(5), range(5)):
        a.append(boards[x][y])
    for x, y in zip(range(5), range(4,-1,-1)):
        b.append(boards[x][y])
    if sum(a) == 0:
        bingo +=1
    if sum(b) == 0:
        bingo += 1
    return bingo

bingo = 0
hash = {}
for r in range(5):
    for c in range(5):
        hash[boards[r][c]] = (r,c)
count = 0
active = 1
for answer in answers:
    if not active: break
    for item in answer:
        count += 1
        boards[hash[item][0]][hash[item][1]] = 0
        if result(boards) >=3:
            active = 0
            break
print(count)
