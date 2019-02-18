import sys
sys.stdin = open("tournamentcard.txt")

def showdown(data, x, y):
    a = data[x]
    b = data[y]
    if a == b:
        return x
    if a == 1 and  b == 2:
        return y
    if a == 1 and b == 3:
        return x
    if a == 2 and b == 1:
        return x
    if a == 2 and b == 3:
        return y
    if a == 3 and b == 1:
        return y
    if a == 3 and b == 2:
        return x

def hap(data, start, end):
    if end-start >=1:
        middle = int((start+end)/2)
        return showdown(data, hap(data, start, middle), hap(data, middle+1, end))
    if start == end:
        return start
    
    
        

for tc in range(int(input())):
    N = int(input())
    data = list(map(int, input().split()))
    print(f"#{tc+1} {hap(data, 0, N-1) + 1}")
