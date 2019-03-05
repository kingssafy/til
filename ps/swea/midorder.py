import sys
sys.stdin = open("midorder_input.txt")
    
def inorder(array, i):
    if 2*i < len(array): inorder(array, 2*i)
    print(array[i], end="")
    if 2*i+1 < len(array): inorder(array, 2*i+1)
for tc in range(1, 11):
    N = int(input())
    tree = [0]
    for _ in range(N): tree.append(input().split()[1])
    inorder(tree, 1);print()
