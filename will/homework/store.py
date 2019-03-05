import sys
sys.stdin = open("store_input.txt")
N = int(input())
polls = []
for _ in range(N):
    polls.append(tuple(map(int, input().split())))
polls.sort()
where = [item[0] for item in polls]
height = [item[1] for item in polls]
target = 0
s = 0
for idx in range(1, len(polls)):
    if height[idx] >= height[target]:
        s += (where[idx]-where[target])*height[target]
        target = idx
    if height[idx] < height[target]:
        if height[idx] >= max(height[idx+1:]+[0]):
            s+= (where[idx]-where[target]-1)*height[idx]
            s+= height[target]
            target = idx
s+= height[-1]
print(s)
