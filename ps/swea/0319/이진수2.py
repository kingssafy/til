T = int(input())
for tc in range(T):
    result = ""
    N = float(input())
    for _ in range(13):
        if N == 0: break
        N = N*2;
        if N >= 1.0:
            N -= 1
            result += "1"
        else:
            result += "0"
    else:
        result = "overflow"
    print(f"#{tc+1} {result}")
            
