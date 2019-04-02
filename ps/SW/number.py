import sys
sys.stdin = open("number_input.txt")

T = int(input())
def getResult(a, op, b):
    if op == 0:
        return a +b
    if op == 1:
        return a - b
    if op == 2:
        return a*b
    return int(a/b) #a//b -> wrong -2/3 = -1.5 ; -2//3 = -2
def dfs(N, depth, curNum):
    if depth == N-1:
        global minimum, maximum
        maximum = max(maximum, curNum)
        minimum = min(minimum, curNum)
    else:
        for i in range(4):
            if ops[i]:
                ops[i] -= 1
                dfs(N, depth+1, getResult(curNum,i,nums[depth]))
                ops[i] += 1

for tc in range(T):
    N = int(input())
    ops = list(map(int, input().split())) # +, -, *, //
    nums = list(map(int, input().split()))
    curNum = nums.pop(0)
    maximum = -99999999  # maximum =0 -> wrong
    minimum = 999999999
    dfs(N, 0, curNum)
    print(f"#{tc+1} {maximum-minimum}")
