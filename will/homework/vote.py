import sys
sys.stdin = open("vote_input.txt")
first = {3:0, 2:0, 1:0}
second = {3:0, 2:0, 1:0}
third = {3:0, 2:0, 1:0} 
def many(diction):
    result = 0
    for key, value in diction.items():
        result += key*value
    return result

N = int(input())
select = 0
for _ in range(N):
    a,b,c = map(int, input().split())
    first[a] += 1
    second[b] += 1
    third[c] += 1
rank = [(many(first),first[3],first[2],1),(many(second),second[3],second[2],2), (many(third),third[3],third[2],3)]
rank.sort(reverse=True)
if rank[0][:3] == rank[1][:3]:
    print(0, rank[0][0])
else:
    print(rank[0][3], rank[0][0])

