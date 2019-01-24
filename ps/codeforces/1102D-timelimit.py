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
while [value for value in counters.values()] != [0, 0, 0]:
    for char in s:
        if counters[char] > 0:
            for word, count in counters.items():
                if int(char) > int(word) and count < 0:
                    s = s.replace(char, word, 1) 
                    counters[char] -= 1
                    counters [word] += 1
                    break
    else:
        break

s = s[::-1]
while [value for value in counters.values()] != [0, 0, 0]:
    for char in s:
        if counters[char] > 0:
            if counters["2"] < 0:
                s = s.replace(char, "2", 1)
                counters[char] -= 1
                counters["2"] += 1
                continue
            if counters["1"] < 0:
                s = s.replace(char, "1", 1)
                counters[char] -= 1
                counters["1"] += 1
                continue

s = s[::-1]

print(s)


