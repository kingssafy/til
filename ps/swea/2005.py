T = int(input())
for tc in range(T):
    array = [0]*11
    array[1] = 1
    n = int(input())
    print(f"#{tc+1}")
    for i in range(1,n+1):
        temp2 = 0
        for k in range(1, i+1):
            temp = array[k]
            print(array[k] + temp2, end=" ")
            array[k], temp2 = array[k] + temp2, temp
        print()
