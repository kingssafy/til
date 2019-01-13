def fib(seq):
    if seq == 1:
        return 1
    if seq == 0:
        return 0
    return fib(seq-1) + fib(seq-2)

print(fib(10))
