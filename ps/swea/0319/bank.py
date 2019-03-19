T = int(input())

def btd(n):
    result = 0
    counter = 0
    while n != 0:
        n, r = divmod(n, 10)
        if r:
            result += 2**counter
            b.append(-(2**counter))
        else:
            b.append(2**counter)
        counter += 1;
    return result
def ttd(n):
    result = 0
    counter = 0
    while n != 0:
        n, r = divmod(n, 10);
        result += r*(3**counter)
        if r == 1:
            t.append(3**counter)
            t.append(-(3**counter))
        elif r == 2:
            t.append(-(3**counter))
            t.append(-2*(3**counter))
        elif r == 0:
            t.append(3**counter)
            t.append(2*(3**counter)) 
        counter += 1
    return result

for tc in range(T):
    b = []
    t = []
    bin = int(input())
    bin = btd(bin)
    tri = int(input())
    tri = ttd(tri)
    for idx in range(len(b)):
        b[idx] += bin 
    for idx in range(len(t)):
        t[idx] += tri
    print(b)
    print(t)
    result = "1"
    b.sort(reverse=True)
    for a in b:
        if a in t:
            result = a
            break
    print(f"#{tc+1} {result}") 
