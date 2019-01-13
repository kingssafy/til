N = 6

liszt = []
str_0 = (" " * (N-1)) +   "*" + (" " * (N-1)) 
str_1 = (" " * (N-2)) +  "* *" + (" " * (N-2))
str_2 = (" " * (N-3)) + "*****" + (" " * (N-3))

liszt.append(str_0)
liszt.append(str_1)
liszt.append(str_2)
# drawing the first chunk
def make_str(liszt,dif):

    if dif > 0:
        from_str = liszt[-dif]
        new_str = from_str[dif:].rstrip()
        while len(new_str) < N:
            new_str += " "
        org_len = len(new_str)
        for n in range(1,org_len):
           new_str += new_str[org_len-(n+1)]
    return new_str        

for l in range(3, N):
    
    # making dif 
    K = int(l)
    if K != 3:
        if (K/3) != 1 :
            K = K/3
            while K >= 2:
                K = K/2
            else:
                if K == 1:
                    dif += dif
    elif K == 3:
        dif = 3

    # let's append!
    liszt.append(make_str(liszt,dif))

for ala in liszt:
    print(ala)