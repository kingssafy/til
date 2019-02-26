import sys
sys.stdin = open("rotate_input.txt")

for tc in range(int(input())):
    N, M = map(int, input().split())
    array = list(map(int, input().split()))
    print(f"#{tc+1} {array[M%N]}")
