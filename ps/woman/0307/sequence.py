import sys
sys.stdin = open("sequence_input.txt")

N = int(input())
sequence = list(map(int, input().split()))
asc = 0
dsc = 0
asc_before = sequence[0]
dsc_before = sequence[0]
maximum = 0
for num in sequence:
    if asc_before <= num:
        asc +=1
    else:
        asc = 1
    if dsc_before >= num:
        dsc +=1
    else:
        dsc =1
    maximum = max(maximum, asc, dsc)
    asc_before = dsc_before = num
print(maximum)
