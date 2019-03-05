import sys
sys.stdin = open("duty_input.txt")
total = 0
for _ in range(5):
    x, y = map(float, input().split())
    temp = max(y-x-1, 0)
    total += min(temp, 4.0)
if total >=15:
    result = total*0.95
elif total <= 5:
    result = total *1.05
else:
    result = total
print(int(result*10000))
