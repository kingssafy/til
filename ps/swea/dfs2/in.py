import sys
sys.stdin = open("in.txt", "r")

T = int(input())

for tc in range(T):
    N, M = map(int, input().split())
    counter = [0]*10
