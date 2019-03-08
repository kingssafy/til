import sys
sys.stdin = open("spy_input.txt")

N, array = input().split()
N = int(N)
level = {}
for i in range(0, 51):
    level[i] = []
l = 0
spy =""
order = []
for char in array:
    if char in '0123456789':
        spy += char
        continue
    if char == "<":
        if spy:
            level[l].append(spy)
        l += 1
        spy =""
        continue
    if char == ">":
        if spy:
            level[l].append(spy)
        spy=""
        l -= 1
        continue


print(*level[N])
