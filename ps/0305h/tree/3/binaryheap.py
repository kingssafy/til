import sys
sys.stdin = open("input.txt")

def parent(node):
    if node <= 1:
        return False
    else:
        return node//2

for tc in range(int(input())):
    N = int(input()) #자연수의 갯수
    array = list(map(int, input().split()))
    heap = [0]
    end = 0
    while array:
        heap.append(array.pop(0))
        end += 1
        child = end
        while parent(child) and heap[parent(child)]>heap[child]:
            heap[parent(child)], heap[child] = heap[child], heap[parent(child)]
            child = parent(child)
    summation = 0
    last = len(heap)-1
    while parent(last):
        summation += heap[parent(last)]
        last = parent(last)
    print("#{} {}".format(tc+1, summation))