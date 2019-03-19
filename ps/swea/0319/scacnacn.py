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
for tc in range(10):
    N, M = map(int, input().split()) 
    grid = [list(input()) for _ in range(N)]
    zipzip = []

    for row in grid:
        check = "".join(row)
        if check != "0"*M and check not in zipzip: 
            zipzip.append(check)
    cypher=""
    cyphers = []
    for row in zipzip:
        for i in row:
            cypher += dtb(htd(i))
        cyphers.append(cypher)
        cypher=""
    final = 0
    stuck = []
    for cypher in cyphers:
        i = len(cypher) -1;
        rythm = []
        while i >= 0:
            if cypher[i] != "0":
                for s in range(1, 250):
                    value = cypher[i+1-7*s:i+1:s]
                    if value in code:
                        rythm.append(code[value])
                        i = i-7*s+1
                        cypher = cypher.replace(cypher[i+1-7*s:i+1],"0"*7*s)
                        print(value)
                        if len(rythm) == 8:
                            stuck.append(rythm[:])
                            print(rythm)
                            rythm = []
                        break
            else:
                i -= 1;
    for rythm in stuck:
        rythm.reverse()
        result = 0
        for idx, value in enumerate(rythm):
            if idx % 2:
                result += value
            else:
                result += 3*value
        if result % 10:
            result = 0
            pass
        
        else:
            final += sum(rythm)
    print(f"#{tc+1} {final}")
