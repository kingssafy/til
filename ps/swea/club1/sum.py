T = int(input())
for tc in range(T):
    N = int(input())
    array = list(map(int, input().split()))
    max = 0;
    temp = 0;
    for d in array:
        temp += d;
        if temp > max:
            max = temp
        elif temp < 0:
            temp = 0
    print(f"#{tc+1} {max}")

