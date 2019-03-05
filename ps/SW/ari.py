import sys
sys.stdin = open("ari_input.txt")
def rchild(array, node):
    if node and node in child:
        return child[node][1]
def lchild(array, node):
    if node and node in child:
        return child[node][0]

def ari(array, node):
    if node and str(array[node]) in '+-/*':
        ari(array, lchild(array, node))
        ari(array, rchild(array, node)) 
        operator = array[node]
        rvalue = array[rchild(array,node)]
        lvalue = array[lchild(array,node)]
        if operator == '+':
            array[node] = rvalue + lvalue
        elif operator == '-':
            array[node] = lvalue - rvalue
        elif operator == '*':
            array[node] = lvalue * rvalue
        elif operator == '/':
            array[node] = lvalue / rvalue


for tc in range(1,11):
    N = int(input())
    array = list(range(N+1))
    child = {}
    for _ in range(N):
        inputs = list(input().split())
        if inputs[1] not in '+/*-':
            array[int(inputs[0])] = int(inputs[1])
        else:
            array[int(inputs[0])] = inputs[1]
            child[int(inputs[0])] = [int(inputs[2]), int(inputs[3])]
    ari(array, 1)
    print(f"#{tc} {int(array[1])}")
