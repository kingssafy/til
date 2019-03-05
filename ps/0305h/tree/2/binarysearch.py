import sys
sys.stdin = open("input.txt")
def makebt(array, parent, now):
    global num
    if parent >= 1 and parent < len(array):
        makebt(array, parent*2, now)
        num +=1
        array[parent] = num
        makebt(array, parent*2+1, now)





for tc in range(int(input())):
    N = int(input())
    array = list(range(N+1))
    num=0
    makebt(array, 1,0)
    print("#{} {} {}".format(tc+1, array[1], array[int(N/2)]))
