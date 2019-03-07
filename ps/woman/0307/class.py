import sys
sys.stdin = open("class_input.txt")

T = int(input())
for tc in range(1, T+1):
    N, minimum, maximum = map(int, input().split())
    given = list(map(int, input().split()))
    scores = {}
    for item in given:
        if item in scores:
            scores[item] += 1
        else:
            scores[item] = 1
    maximumscore = max(given)
    result = 999999
    for T1 in range(1, maximumscore):
        for T2 in range(T1+1, maximumscore+1):
            A = 0
            B = 0
            C = 0
            for key, value in scores.items():
                if key < T1:
                    A += value
                if T1 <= key < T2:
                    B += value
                if T2 <= key:
                    C += value
            if minimum<= A <=maximum and minimum<=B<=maximum and minimum<=C<=maximum:
                temp = max(A,B,C) - min(A,B,C)
                if temp < result:
                    result = temp
    if result == 999999:
        print(-1)
    else:
        print(result)