primes = [2]
primes += list(range(3,1001,2))
for i in primes:
    if i in primes:
        m = int(i)
        while  m < 334:
            if i*m in primes:
                primes.remove(i*m)
            m += 1

print(primes)