import sys
sys.stdin = open("range.txt")
T = int(input())
buttons = [300, 60, 10]
result = [0, 0, 0]
for idx, button in enumerate(buttons):
    q, r = divmod(T, button)
    T = r
    result[idx] = q
    
if r:
    print("-1")
else:
    print(*result)
