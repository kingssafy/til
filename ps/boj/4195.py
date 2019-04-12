import sys
sys.stdin = open("4195_input.txt")
T = int(input())
link = {}
size = {}
def find(x):
    if x not in link: 
        link[x] = x;
    while x != link[x]:
        x = link[x]
    return x;

def same(a, b):
    return find(a) == find(b)
def unite(a, b):
    a = find(a)
    b = find(b)
    if size[a] < size[b]:
        a, b = b, a
    link[b] = a;
    size[a] += size[b]

for tc in range(T):
    size.clear()
    link.clear()
    F = int(input())
    for _ in range(F):
        a, b = input().split() 
        if a not in size:
            size[a] = 1
        if b not in size:
            size[b] = 1
        if not same(a, b):
            unite(a, b);
        print(size[find(a)])

