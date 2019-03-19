import sys
sys.stdin = open("1289_input.txt");

T = int(input())
for tc in range(T):
    array = input()
    flag = 0;
    count = 0;
    for bit in array:
        if int(bit) != flag:
            count += 1
            flag = int(not(flag))
    print(count)
