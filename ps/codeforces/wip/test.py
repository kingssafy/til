import sys
sys.stdin = open("1129A1.txt");

n, m = map(int, input().split())
distance, count = {}, {};
for _ in range(m):
    fr, to = map(int, input().split())
    count[fr] = count[fr] + 1 if fr in count else 1
    distance[fr] = min(distance[fr], (to+n-fr)%n) if fr in distance else (to+n-fr)%n

for i in range(1, n+1):
    print(
            max(
                ((j-i) + distance[j] + n*(count[j] -(j>=i))  for j in count) 
                )
            , end=" "
            )

