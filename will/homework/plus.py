import sys
sys.stdin = open("plus_input.txt")

string, target = input().split()
target = int(target)
for idx in range(1,len(string)):
    sa = int(string[:idx])
    sb = int(string[idx:])
    if sa+sb == target:
        print(f"{sa}+{sb}={target}")
        break
else:
    print("NONE")
