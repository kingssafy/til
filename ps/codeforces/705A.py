def a(n):
    if n ==1:
        return ""
    b = "I love that " if n%2 else "I hate that "
    return a(n-1) + b
n = int(input()) 
b = "I hate it" if bool(n%2) else "I love it"
print(a(n) + b)

