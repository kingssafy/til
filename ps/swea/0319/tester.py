import sys
sys.stdin = open("code_input.txt")
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
    grid = [list(input()) for _ in range(N)]
    for r in grid:
            ch = "".join(r)
        if ch != "0"*M: 
                tt = r
            break
    cp=""
    for i in tt:
            cp += dtb(htd(i))
    i = len(cp) -1;
    rythm = []
    while i >= 6:
            if cp[i] != "0":
                    for s in range(1, 11):
                            value = cp[i+1-7*s:i+1:s]
                if value in code:
                        rythm.append(code[value])
                    i = i-7*s
                    break
        else:
                i -= 1;
    rythm.reverse()
    result = 0
    for idx, value in enumerate(rythm):
            if idx % 2:
                    result += value
        else:
                result += 3*value
    if result % 10:
            print(f"#{tc+1} 0")
    else:
            print(f"#{tc+1} {sum(rythm)}")
