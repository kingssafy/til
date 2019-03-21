import sys
sys.stdin = open("scan_input.txt") 

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
    print(raws)
    binaries = []
    for raw in raws:
        cypher = ""
        for c in raw:
            cypher += dtb(htd(c));
        binaries.append(cypher)
    items = []
    for binary in binaries:
        temp = ""
        tempa = []
        step =0
        print(binary)
        for c in binary[::-1]:
            if not temp and c == "0":
                pass
            else:
                temp += c
                if len(temp) % 7 == 0 and not step:
                    step = len(temp)//7
                    val = temp[::-1][::step]
                    if val in code:
                        value = code[val] 
                        tempa.append(value)
                        print(temp, val)
                        temp =""
                        if len(tempa) == 8:
                            tempa.reverse()
                            if tempa not in items:
                                items.append(tempa[:])
                            tempa.clear()
                
    final = 0
    for hack in items:
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

