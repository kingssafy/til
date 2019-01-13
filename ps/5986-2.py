# primes = [2]
# primes += list(range(3,1000,2))

# for i in range(2,1000):
#     if i in primes:
#         m = int(i)
#         while i*m in primes:
#             primes.remove(i*m)
#             m += 2

T = int(input())
for test_case in range(1, T + 1):
    K = int(input())

    tempset = set()
    if test_case ==1:
        primes = [2]
        primes += list(range(3,1001,2))
        for i in primes:
            if i in primes:
                m = int(i)
                while i*m in primes:
                    primes.remove(i*m)
                    m += 2
                
    for i in primes:
        if i <= K/2:
            N = int(K)
            N = N-i
            for k in primes[primes.index(i):]:
                if N-k in primes:
                    tempset.add(frozenset({i,k,N-k}))
        else:
            break

    print(f"#{test_case} {len(tempset)}")