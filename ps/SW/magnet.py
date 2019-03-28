import sys
sys.stdin = open("magnet_input.txt")

T = int(input())
def rotate(array, clockwise):
    if clockwise:
        array.insert(0, array.pop())
    else:
        array.append(array.pop(0))
    return True

def gorecurse(magnets, index, clockwise):
    left = index -1
    right = index +1
    if index not in done:
        done.append(index)
        if 4 > left >= 0 and magnets[index][-2] != magnets[left][2]:
            gorecurse(magnets, left, not clockwise)
        if 0<=right < 4 and magnets[index][2] != magnets[right][-2]:
            gorecurse(magnets, right, not clockwise)
        rotate(magnets[index], clockwise)


for tc in range(1, T+1):
    K = int(input()) #howmany rounds
    magnets = [list(map(int, input().split())) for _ in range(4)]
    done = []
    for _ in range(K):
        which, clockwise = map(int, input().split())
        which -= 1
        if clockwise == 1:
            clockwise = True
        else:
            clockwise = False
        gorecurse(magnets, which, clockwise)
        done.clear()

    score = sum(2**n for n, row in enumerate(magnets) if row[0])
    print("#{} {}".format(tc,score))
