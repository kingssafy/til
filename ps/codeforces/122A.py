n = int(input())
for i in range(1, int(n/4)+1):
    x, y = divmod(n, i)
    if y == 0 and set(str(x)) <= set("47"):
        print("YES")
        break
else:
    print("NO")
