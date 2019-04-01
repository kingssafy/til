import sys
sys.stdin = open("mst_input.txt")

def find(x):
    while x != link[x]: x = link[x]
    return x

def same(a, b):
    return find(a) == find(b)

def unite(a, b):
    a = find(a)
    b = find(b)
    if size[a] < size[b]:
        a, b = b, a
    link[b] = a
    size[a] += size[b]
    return None;



T = int(input())
for tc in range(T):
    V, E = map(int, input().split())
    link = list(range(V+1))
    size = [1 for _ in range(V+1)]
    edges = []
    for _ in range(E):
        a, b, w = map(int, input().split()) 
        edges.append((a,b,w))
    edges.sort(key = lambda x: x[2])
    result = 0;
    for a, b, w in edges:
        if not same(a, b):
            unite(a, b)
            result += w;
    print(f"#{tc+1} {result}")
