import sys
sys.stdin = open("bricks_input.txt")

T = int(input())

for tc in range(T):
    N, W, H = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(H)]
