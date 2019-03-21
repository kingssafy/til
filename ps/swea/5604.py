T = int(input())
for tc in range(T):
    A, B = map(int, input().split())
    result = 0
    for num in range(A, B + 1):
        result += sum(map(int, str(num)))
    print(f"#{tc+1} {result}")
