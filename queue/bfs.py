n = 7
string = '1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7'
string = list(map(int, string.split()))
nodes = [(string[2*x], string[2*x+1]) for x in range(len(string)//2)]



visited = []
stack = []
start = 1
stack.append((start,0))

while stack:
    a, d = stack.pop(0)
    if a not in visited:
        visited.append(a)
        print(a, "distance", d)
        for node in nodes:
            if a == node[0] and node[1] not in visited:
                stack.append((node[1], d+1))
        
