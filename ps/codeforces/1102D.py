n = int(input())
s = input()

# count the number of "0", "1", "2" in given string
# make dict {"0":x,"1":y,"2":z}
# iterate through given string until make all the value in count dict into n/3
# left to right. 2 to 0
counters = {"0":0, "1":0, "2":0}
each = int(n/3)
def king():
    for char in s:
        counters[char] += 1
    for key in counters:
        counters[key] -= each
king()
backward = "210"
for back in backward:
    if counters[back] > 0:
        for num, counts in counters.items():
            if counts < 0 and int(num) < int(back):
                changes = min(abs(counts), counters[back])
                s = s.replace(back, num, changes)
                counters[back] -= changes
                counters[num] += changes


s = s[::-1]
for back in backward:
    if counters[back] < 0:
        for num, counts in counters.items():
            if counts > 0 and int(back) > int(num): 
                changes = min(counts, abs(counters[back]))
                s = s.replace(num, back, changes)
                counters[back] -= changes
                counters[num] += changes

s = s[::-1]
print(s)
