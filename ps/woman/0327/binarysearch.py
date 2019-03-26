array = [0]*1000000
input()
a = list(map(int, input().split()))
for idx, value in enumerate(a, 1):
    if not array[value]:
        array[value] = idx
N= int(input())
for a in map(int, input().split()):
    print(array[a])

