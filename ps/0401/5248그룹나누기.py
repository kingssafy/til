import sys
sys.stdin = open("5248_input.txt");
def find(x):
    while link[x] != x: x = link[x]
    return x;
def same(a, b):
    return find(a) == find(b)
def unite(a, b):
    a = find(a)
    b = find(b)
    if size[a] < size[b]:
        a, b = b, a
    size[a] += size[b]
    link[b] = a

T = int(input())
for tc in range(T):
    N, M = map(int, input().split())
    link = list(range(N+1))
    size = [1] * (N+1)
    arr = list(map(int, input().split()))
    
    for i in range(M):
        unite(arr[2*i], arr[2*i+1])
    parents = [find(x) for x in range(N+1)]
    b = set(parents)
    print(f"#{tc+1} {len(b)-1}")
    
