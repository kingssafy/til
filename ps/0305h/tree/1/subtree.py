import sys
sys.stdin = open("input.txt")

def getsize(array, node):
    if node not in childs:
        return 1
    frontier = childs[node]
    counter = 1

    while frontier:
        next = []
        for i in frontier:
            counter += 1
            if i in childs:
                for j in childs[i]:
                    next.append(j)
        frontier = next
    return counter

for tc in range(int(input())):
    childs = {}
    parent = {}
    E, N = map(int, input().split()) #간선의 개수 E 목표N
    edges = list(map(int, input().split()))
    for idx in range(int(len(edges)/2)):
        p = edges[2*idx]
        c = edges[2*idx+1]
        if p not in childs:
            childs[p] = [c]
        else:
            childs[p].append(c)
        if c not in parent:
            parent[c] = [p]
        else:
            parent[c].append(c)

    print("#{} {}".format(tc+1, getsize(childs, N)))