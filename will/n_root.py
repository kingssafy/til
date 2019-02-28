import sys
sys.stdin = open("n_root_input.txt")

def digitroot(n):
    if n < 10:
        return n
    return digitroot(n//10) + n%10

def recurse(n):
    answer = n
    while answer >9:
        answer = digitroot(n)
    return answer

print(recurse(65536))
