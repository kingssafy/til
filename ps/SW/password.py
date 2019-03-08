import sys
sys.stdin = open("password_input.txt")

alphabet = {
        "A":10,
        "B":11,
        "C":12,
        "D":13,
        "E":14,
        "F":15,
        }
def rotate(array):
    array.insert(0,array.pop())
def getnums(array):
    a = "".join(array[:numleng])
    b = "".join(array[numleng:2*numleng])
    c = "".join(array[2*numleng:3*numleng])
    d = "".join(array[3*numleng:])
    return tuple(map(hextoint, (a,b,c,d))) 

def hextoint(hex):
    place = len(hex)
    result = 0
    for idx, char in enumerate(hex):
        if char in alphabet:
            factor = alphabet[char]
        else:
            factor = int(char)
        result += factor *(16**(place-(idx+1)))
    return result


T = int(input())
for tc in range(1, T+1):
    N, K = map(int, input().split()) # #nums, #order
    array = list(input())
    numleng = N//4
    nums = []
    gettings = getnums(array)
    for i in gettings:
        if i not in nums:
            nums.append(i)
    before = len(nums)
    now = False
    while before != now:
        before = now
        for _ in range(N): 
            rotate(array)
            gettings = getnums(array)
            for i in gettings:
                if i not in nums:
                    nums.append(i) 
            
        now = len(nums)
    nums.sort(reverse=True)
    print(f"#{tc} {nums[K-1]}")
