N = int(input())
for _ in range(N):
    string = input()
    a = sorted(string)
    before = a[0];
    flag = 1;
    for x in a[1:]:
        if ord(before)+1 == ord(x):
            before = x
        else: 
            flag = 0
            break;
    if flag:
        print("YES")
    else:
        print("NO")

