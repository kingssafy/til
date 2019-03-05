import sys
sys.stdin = open("prime_input.txt")

def pg(n):
    nroot = int(n ** 0.5)
    sieve = list(range(n+1))
    sieve[1] = 0
    for i in range(2, nroot + 1):
        if sieve[i]:
            m = int(n/i - i)
            sieve[i * i: n + 1: i] = [0] * (m + 1)
    sieve = [x for x in sieve if x]
    return sieve


a, b = map(int, input().split())
m = min(a, b)
M = max(a, b)
primes = pg(M)
for idx in range(len(primes)):
    if primes[idx] >= m:
        break
print(len(primes) - idx)
print(primes[idx] + primes[-1])
