import sys
sys.stdin = open("prime.txt")

T = int(input())
for tc in range(T):
    D, A, B = map(int, input().split())
    j = list(range(B+1))
    j[1] = 0
    m = int(B**1/2) +1
    for i in range(2, m):
        if j[i]:
            j[i*i:B+1:i] = [0]*(B//i-i+1)
    primes = [x for x in j if x and x >= A]
    count = 0
    for prime in primes:
        while prime > 0:
            prime, r = divmod(prime, 10)
            if r == D:
                count += 1
                break
    print(f"#{tc+1} {count}")
