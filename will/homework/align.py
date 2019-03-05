import sys
sys.stdin = open("align_input.txt")

N = int(input())
picks = list(map(int, input().split()))
array = list(range(1,N+1))
def swap(array, person, pick):
    idx = person - 1
    for i in range(pick):
        array[idx-i-1], array[idx-i] = array[idx-i], array[idx-i-1]

for person, pick in enumerate(picks, 1):
    swap(array, person, pick)

print(*array)

