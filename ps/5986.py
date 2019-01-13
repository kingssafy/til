# primes = [2]
# primes += list(range(3,1000,2))

# for i in range(2,1000):
#     if i in primes:
#         m = int(i)
#         while i*m in primes:
#             primes.remove(i*m)
#             m += 2

T = int(input())
primes = [2]
primes += list(range(3,1001,2))
for i in primes:
    if i in primes:
        m = int(i)
        while  m < 334:
            if i*m in primes:
                primes.remove(i*m)
            m += 1
for test_case in range(1, T + 1):
    templist = []
    result = 0
    K = int(input())    
    for i in primes:
        if i <= K/2:
            N = int(K)
            N = N-i
            for k in primes:
                if k < N:
                    if N-k in primes:
                        if {i,k,N-k} not in templist:
                            templist.append(frozenset({i,k,N-k}))

                else:
                    break
        else:
            break
    print(f"#{test_case} {len(templist)}")