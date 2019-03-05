R = int(input())
count = 0
for r in range(R):
    for c in range(R):
        dfo = (r+1)**2+(c+1)**2
        if dfo <= R**2:
            count += 1

print(count*4)
