import sys

sys.stdin = open("나사문제_input.txt")

for T in range(int(input())):
    n = int(input()) #막대의갯수
    pieces = list(map(int, input().split()))
    l = [piece for idx, piece in enumerate(pieces) if not idx%2]
    r = [piece for idx, piece in enumerate(pieces) if idx%2]
    comp = list(map(list,zip(l,r)))
    

    counts = [0]*100
    for i in pieces:
        counts[i] += 1

    for solo in l:
        if counts[solo] ==1:
            startl = solo
    


    start = startl

    print(f"#{T+1}",end="")
    for piece in comp:
        if piece[1] == start:
            a = comp.pop(comp.index(piece))
            print(f" {a[0]} {a[1]}", end = "")
            break
    
    while comp:
        for piece in comp:
            if piece[0] == start:
                a = comp.pop(comp.index(piece))
                print(f" {a[0]} {a[1]}", end="")
                start = a[1]
    print()
