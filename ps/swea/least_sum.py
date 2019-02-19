import sys
sys.stdin = open("least_sum_input.txt")


def recurse(row, n):
    global mean
    row += 1
    currentsum = sum(boards[key][value] for key, value in enumerate(answersheet[0:row])) 
    if currentsum > mean:
        return
    if row == n:
        currentsum = sum(boards[key][value] for key, value in enumerate(answersheet))
        if currentsum < mean:
            mean = currentsum
            return
    for column in range(n):
        if column not in answersheet[0:row]:
            answersheet[row] = column
            recurse(row, n)

for tc in range(int(input())):
    n = int(input())
    boards = [list(map(int, input().split())) for _ in range(n)]
    answersheet = [-1] *n
    row = -1
    mean = 999
    recurse(row, n)
    print(f"#{tc+1} {mean}")
