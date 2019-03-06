import sys
sys.stdin = open("chocolate_input.txt")

N = int(input())
count = 0
for _ in range(N):
    L, H = input().split()
    l = {}
    h = {}
    for char in L:
        if char in l:
            l[char] += 1
        else:
            l[char] = 1
    for char in H:
        if char in h:
            h[char] += 1
        else:
            h[char] = 1
    for dic in (l, h):
        if max(dic.values()) > 1:
            count += 1
            break
        if len(set(L)& set(H)) >=3:
            count +=1
            break

print(count)
