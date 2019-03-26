input()
counter = {}
for a in map(int, input().split()):
    if a in counter:
        counter[a] += 1;
    else:
        counter[a] = 1;
input()
for a in map(int, input().split()):
    if a in counter:
        print(counter[a], end= " ")
    else:
        print(0, end=" ")
