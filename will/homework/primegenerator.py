def pg(n):
    nroot = int(n**0.5)
    sieve = list(range(n+1))
    sieve[1] = 0

    for i in range(2, nroot+1):
        if sieve[i]:
            m = int(n/i-i)
            sieve[i*i::i] = [0]*(m+1)
    sieve = [x for x in sieve if x]
    return sieve

print(pg(10000000))
