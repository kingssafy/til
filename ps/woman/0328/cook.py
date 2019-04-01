import sys
sys.stdin = open("cook_input.txt");


def dfs(k, curMul, curSum):
    if k == N:
        if not curMul == 0 and not curSum==0:
            global maximum
            maximum = min(maximum, abs(curMul-curSum)) 
    else: 
        dfs(k+1, curMul*recipes[k][0], curSum+recipes[k][1])
        dfs(k+1, curMul, curSum);



N = int(input())
visit = [0] * 10;
recipes = []
for i in range(N):
    recipes.append(tuple(map(int, input().split())))
maximum = 9999999999999
dfs(0, 1, 0);
print(maximum);
