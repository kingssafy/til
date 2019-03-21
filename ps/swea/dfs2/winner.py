T = int(input())

for tc in range(T):
    string, N = input().split()
    N = int(N)
    string = list(map(int, string))
    while N > 0:
        for i in range(len(string)):
            ms = max(string[i+1:])
            if string[i] == ms:
                pass
            else:
                flag = 1
                c = 0
                for ix in range(len(string)-1, i, -1): 
                    if string[ix] == ms:  
                        c += 1
                        if c >= N:
                            string[i], string[ix] = string[ix], string[i]
                            N -= 1
                            flag = 1
                            break
                if flag:
                    break
        else:
            string[-1], string[-2] = string[-2], string[-1]
            N -= 1

    print(f"#{tc+1} ", *string, sep="")
