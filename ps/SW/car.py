import sys
sys.stdin = open("car_input.txt")

T = int(input())
for tc in range(T):
    N, M, K, A = map(int, input().split())  
    receptions = list(map(int, input().split()))
    repairs = list(map(int, input().split()))
    customers = map(int, input().split())
    

