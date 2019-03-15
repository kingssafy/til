T = int(input())
for i in range(T):
    print(f"#{i+1}")
    N = int(input())
    for j in range(N):
        print(" ".join(str(11**j)))
