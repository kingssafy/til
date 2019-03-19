import sys
sys.setrecursionlimit(1000000)

n=int(input())
r1,c1=map(int,input().split())
r2,c2=map(int,input().split())
a=[]
for i in range(n):
	a.append(input())
a1=[]
a2=[]
def dfs1(i,j):
	if (i,j) in a1:
		return
	if max(i,j)>=n or min(i,j)<0:
		return
	if a[i][j]=='1':
		return
	a1.append((i,j))
	dfs1(i+1,j)
	dfs1(i-1,j)
	dfs1(i,j+1)
	dfs1(i,j-1)
	return
def dfs2(i,j):
	if (i,j) in a2:
		return
	if max(i,j)>=n or min(i,j)<0:
		return
	if a[i][j]=='1':
		return
	a2.append((i,j))
	dfs2(i+1,j)
	dfs2(i-1,j)
	dfs2(i,j+1)
	dfs2(i,j-1)
	return
dfs1(r1-1,c1-1)
print(a1)
if (r2-1,c2-1) in a1:
	print(0)
	exit()
dfs2(r2-1,c2-1)
print(a2)
ans=1e9
for i in a1:
	for j in a2:
		x=(i[0]-j[0])**2 + (i[1]-j[1])**2
		ans=min(ans,x)
print(ans)
