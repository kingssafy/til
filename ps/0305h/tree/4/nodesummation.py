import sys
sys.stdin = open("input.txt")

def leftchild(tree, target):
    return target*2 if target*2 < len(tree) else 0

def rightchild(tree, target):
    return target*2+1 if target*2+1 < len(tree) else 0

def makesum(tree, target):
    tree[target] = tree[leftchild(tree, target)] + tree[rightchild(tree, target)]

for tc in range(int(input())):
    N, M, L = map(int, input().split()) # #nodes, #leaves, targetnode
    tree = [0 for _ in range(N+1)]
    for _ in range(M):
        key, value = map(int, input().split())
        tree[key] = value
    for idx in range(N//2, -1,-1):
        makesum(tree, idx)
    print("#{} {}".format(tc+1, tree[L]))