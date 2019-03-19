T = int(input())
def hextobit(n):
    for i in range(3, -1, -1):
        if (1<<i)&n:
            print(1,end="")
        else:
            print(0,end="")

for tc in range(T):
    N, array = input().split()
    print(f"#{tc+1}", end=" ")
    for a in array:
        if a in '0123456789':
            a = int(a)
        else:
            a = 10 +ord(a) - ord("A")
        hextobit(a);
    print();
