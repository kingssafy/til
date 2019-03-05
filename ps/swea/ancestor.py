import sys
sys.stdin = open("ancestor_input.txt")

def getsize(tree, root):
    count = 0
    frontier = [root]
    while frontier:
        next = []
        for node in frontier:
            count += 1
            for hi in tree[node]:
                next.append(hi)
        frontier = next
    return count

for tc in range(int(input())):
    V, E, a, b = map(int, input().split())
    tree = {}
    parent = {}
    for i in range(1, V+1):
        tree[i] = []
        parent[i] = []
    array = list(map(int, input().split()))
    for i in range(0,len(array),2):
        tree[array[i]].append(array[i+1])
        parent[array[i+1]].append(array[i])
    ancestor = {}
    ancestor[a] = []
    ancestor[b] = []
    for i in (a, b):
        father = parent[i]
        while father:
            ancestor[i].append(father[0])
            father = parent[father[0]]
    for i in ancestor[a]:
        if i in ancestor[b]:
            near = i
            break
    print(f"#{tc+1}",i, getsize(tree,i)) 
