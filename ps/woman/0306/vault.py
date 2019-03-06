import sys
sys.stdin = open("vault_input.txt")

N = int(input())
numbers = list(map(int, input().split()))
length = 2*(N-1) +1
grid = [[0 for _ in range(length)] for _ in range(length)]

for i in range(1, N+1):
    grid[i-1][N-i:N+i-1:2] = numbers[((i-1)*i)//2:((i-1)*i)//2 + i]
    grid[length-i][N-i:N+i-1:2] = numbers[::-1][((i-1)*i)//2:((i-1)*i)//2 + i][::-1]
maximum = -9999999
for c in range(length):
    summation = 0
    for r in range(length):
        summation += grid[r][c]
    else:
        maximum = max(summation, maximum)

print(maximum)
