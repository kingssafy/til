N = int(input())
array = list(map(int, input().split()))
M = int(input())
if M >= sum(array):
    print(max(array))
    exit()
high = M+1
def g(n):
    r = 0
    for i in array:
        r += min(i, n)
        if r > M: return True
    return False
x = -1
while high > 0:
    while not g(x+high):
        x += high;
    high //=2

print(x)


