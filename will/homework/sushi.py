import sys
sys.stdin = open("sushi_input.txt")

N, d, k, c = map(int, input().split())
array = [int(input()) for _ in range(N)]
array += array[:k-1]
omakase = []
last = 0 
table = {}
count = 1
for i in range(1, d+1):
    table[i] = 0
    
for sushi in array[:k]:
    omakase.append(sushi)
    if not table[sushi]:
        count += 1
    table[sushi] += 1
    maximum = count
    
table[c] = 1

for sushi in array[k:]:
    table[omakase[last]] -= 1
    if table[omakase[last]] == 0:
        count -=1
    omakase.append(sushi)
    table[sushi] += 1
    if table[sushi] == 1:
        count += 1
    last+=1
    if count > maximum:
        maximum = count
        


print(maximum)

