import sys
sys.stdin = open("pig.txt")

length = int(input())
array = []*length
for _ in range(length):
    idx, value = input().split()
    idx = int(idx)
    array.append((idx,value))
array.sort()
result = "F"
for key, value in array:
    if value == "Y" and result == "F":
        result = key
    elif result != "F" and value == "N":
        result ="F"
        break
print(result)
    
