"""abc"""
def factors(a):
    """ returns factors as list"""
    liszt = [1]
    i = 2
    while i <= a:
        if a % i == 0:
            a = a/i
            liszt.append(i)
        else:
            i += 1
    return liszt

def gcdlcm(a, b):
    """abc"""
    factora = factors(a)
    factorb = factors(b)
    factorc = factors(a)
    factord = factors(b)
    lcm = 1
    gcm = 1
    for i in factora:
        lcm = lcm * i
        if i in factorb:
            factorb.remove(i)

    for i in factorb:
        lcm = lcm*i

    for i in factorc:
        if i in factord:
            gcm = gcm*i
            factord.remove(i)

    return [gcm, lcm]

print(gcdlcm(3, 12))
print(gcdlcm(1071, 1029))
