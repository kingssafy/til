import sys
sys.stdin = open("int.txt")

T = int(input())
for tc in range(T):
    N = int(input())
    checker = list(range(10**N+1))
    array = []
    a = 1 if N < 20 else N//20
    for _ in range(a):
        array += list(input().split())
    for l in range(1,len(array)):
        for i in range(len(array)-l):
            checker[int("".join(array[i:i+l]))] = 1
    print(checker[1:100])
