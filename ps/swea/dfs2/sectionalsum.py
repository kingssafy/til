N = 999
counter = [0]*10

counter =[1,1,1,1,1,1,1,1,1,1]
k=1
N //= 10
while N:
    N, R = divmod(N, 10)
    for i in range(10):
        counter[i] = counter[i] + counter[i]*R + R*(10**k)
    k += 1
print(counter)
result = 0
for i in range(10):
    result += i *counter[i]
print(result)
