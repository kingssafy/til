import sys
sys.stdin = open("cons_input.txt")
N = int(input())
global_max = 0
temp_max = float(input())
for _ in range(N-1):
    now = float(input())
    temp_max *= now
    if temp_max > global_max:
        global_max = temp_max
    if temp_max < 1:
        temp_max = now
print(round(global_max, 3))
