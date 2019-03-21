T = int(input())

for tc in range(T):
    N, B = map(int, input().split())
    heights = list(map(int, input().split()))
    counter = [0] * (sum(heights)+1)
    counter[0] = 1
    for height in heights: 
        for i in range(len(counter)-1, -1, -1):
            if i-height >= 0 and counter[i-height]:
                counter[i] = 1
                print(counter)
    for i in range(B, len(counter)):
        if counter[i]:
            print(f"#{tc+1} {i-B}")
            break
