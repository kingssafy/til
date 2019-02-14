import sys
sys.stdin = open("ladder1_input.txt")

for _ in range(10):
    input()
    ladder = ["".join(input().split()) for _ in range(100)]
    y = ladder[99].find("2")
    for row in reversed(ladder):
        if y+1 < 100 and int(row[y+1]): y = row.rfind("1"); continue
        if y-1 > -1 and int(row[y-1]): y= row.find("1"); continue
    print(f"#{_+1} {y}")