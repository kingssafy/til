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
    binaries = []
    for raw in raws:
        cypher = ""
        for c in raw:
            cypher += dtb(htd(c));
        binaries.append(cypher)
    flag = 0
    bigbag = []
    for binary in binaries:
        idx = len(binary) -1 
        while idx >= 0:
            if binary[idx] == "1":
                for x in range(1, 50):
                    items = []
                    temp = binary[idx-56*x +1:idx+1]
                    start = idx-56*x+1
                    end = idx+1
                    for k in range(1, 9):
                        items.append(binary[start+7*x*(k-1):start+7*x*k:x])
                    for item in items:
                        if item not in code:
                            break
                    else:
                        nail = []
                        for item in items:
                            nail.append(code[item])
                        if nail not in bigbag:
                            bigbag.append(nail)
                        idx = start
                        break
            else:
                pass
            idx -= 1;
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

