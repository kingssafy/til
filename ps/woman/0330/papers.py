import sys
sys.stdin = open("papers_input.txt");

N = int(input())
papers = [];
for _ in range(N):
    papers.append(tuple(map(int, input().split())));
papers.sort(key = lambda x:x[0]*x[1]); #sort by area is the answer
array = [1]*N;
maximum = 0;
for i in range(N):
    for k in range(N):
        
        if i != k and ((papers[k][0] <= papers[i][0] and papers[k][1] <= papers[i][1]) or (papers[k][1] <= papers[i][0] and papers[k][0] <= papers[i][1])):
            array[i] = max(array[i], array[k]+1);
print(max(array));
