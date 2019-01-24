def hanoi(N, A, B, C):
    if N > 0:
        
        hanoi(N-1, A, C, B)
        print(f"move {A} to {C}")
        hanoi(N-1, B, A, C)


hanoi(3,"A","B","C")
