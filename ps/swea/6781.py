import sys
sys.stdin = open("6781_input.txt")

T = int(input())
for tc in range(T):
    n = map(int, input())
    c = input()
    z = {}
    for c, n in zip(c, n):
        if c in z:
            z[c][n] +=1;
        else:
            z[c] = [0]*10
            z[c][n] +=1;
    result = True;
    for num in z.values():
        counter = 0
        how = 9
        for _ in range(3):
            for idx in range(10):
                if num[idx] > 0:
                    counter += 1;
                    how = min(how, num[idx])
                else:
                    counter = 0;
                    how = 9
                if counter == 3:
                    num[idx] -= how
                    num[idx-1] -= how
                    num[idx-2] -= how
                    counter = 0
                    how = 9
                    if num[idx]:
                        counter =1
                        how = min(how, num[idx])
        for idx in range(10):
            num[idx] = num[idx] %3
        flag = sum(num);
        if flag:
            result = False;
    print(result)
