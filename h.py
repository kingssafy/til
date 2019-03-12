a = [1,2,3,4]
selected = [False]*4
b = []
subset = []
def permutation(a):
    n = len(a)
    if len(subset) == len(a):
        print(subset)
    else:
        for i in range(n):
            if selected[i]: continue
            selected[i] = True
            subset.append(a[i])
            permutation(a)
            subset.pop()
            permutation(a)
            selected[i] = False
permutation(a)


def myprint(q):
    while(q):
        q -= 1
        print( " %d" %(t[q]), end ="" )
    print()

def perm(n, r, q):
    if r == 0:
        myprint(q)
    else:
        for i in range(n-1, -1, -1):
            a[i] , a[n-1] = a[n-1], a[i]
            t[r-1] = a[n-1]
            perm(n-1, r-1, q)
            a[i], a[n-1] = a[n-1], a[i]


a = [1,2,3]
t = [0]*3

perm(3,2,2)
