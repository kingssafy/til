import sys
sys.stdin = open("scanner_input.txt") 

code = {
        "0001101": 0,
        "0011001": 1,
        "0010011": 2,
        "0111101": 3,
        "0100011": 4,
        "0110001": 5,
        "0101111": 6,
        "0111011": 7,
        "0110111": 8,
        "0001011": 9,
        }
def htd(n):
    if n in '0123456789':
        n = int(n)
    else:
        n = 10+ord(n) - ord("A")
    return n

def dtb(n):
    result = ""
    for i in range(3,-1,-1):
        if (1<<i)&n:
            result += "1"
        else:
            result += "0"
    return result

T = int(input())

for tc in range(T):
    N, M = map(int, input().split())
    grid = [input() for _ in range(N)]
    raws = []
    for row in grid:
        if row != "0"*M and row not in raws:
            raws.append(row)
    bs = []
    for raw in raws:
        cr = ""
        for c in raw:
            cr += dtb(htd(c));
        bs.append(cr)
    flag = 0
    bigbag = []
    for b in bs:
        i = len(b) -1 
        while i >= 0:
            if b[i] == "1":
                for x in range(1, 50):
                    it = []
                    temp = b[i-56*x +1:i+1]
                    t = i-56*x+1
                    end = i+1
                    for k in range(1, 9):                        it.append(b[t+7*x*(k-1):t+7*x*k:x])
                    for e in it:
                        if e not in code:break
                    else:
                        nail = []
                        for e in it:
                            nail.append(code[e])
                        if nail not in bigbag:
                            bigbag.append(nail)
                        i = t
                        break
            else: pass
            i -= 1;
    final = 0
    for hack in bigbag:
        result = 0
        for idx, n in enumerate(hack):
            if idx%2:
                result += n 
            else:
               result += n*3 
        if result % 10:
            pass
        else:
            final += sum(hack)
    print(f"#{tc+1} {final}")

