import sys
sys.stdin = open("ari_input.txt")
def rchild(array, node):
    if node in child:
        return child[node][1]
def lchild(array, node):
    if node in child:
        return child[node][0]

def ari(array, node):
    if node >= len(array): return
    operator = array[node]
    if str(operator) not in '+/*-':
        return
    right = rchild(array, node)
    left = lchild(array, node)

    if not right or not left:
        return
        ari(array, left)
        ari(array, right)
    if operator =='*':
        value = left * right
    elif operator == '+':
        value = left + right
    if operator == '/':
        value = left / right
    if operator == '-':
        value = left - right
    array[node] = value


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
    print(array, child)
    ari(array, 1)
    print(array)