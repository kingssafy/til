import sys
sys.stdin = open("car_input.txt")
from heapq import heappush, heapify, heappop

T = int(input())
for tc in range(T):
    N, M, K, A, B = map(int, input().split())  
    receptions = list(map(int, input().split()))
    repairs = list(map(int, input().split()))
    customers = list(map(int, input().split()))
    
    print(N, M, K, A, B)
    print(receptions)
    print(repairs)
    print(customers)
    

