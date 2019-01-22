A = [[9, 20, 2, 18, 11],
       [19, 1, 12, 3, 14],
       [8, 13, 10, 17, 7],
       [15, 4, 16, 5, 6]]

def move(original, result, count, now):
    result[now[0]][now[1]] = original[count]

sorting = [elem for row in A for elem in row]
sorting.sort()
directions = {(-1,0):(0, 1),
             (0,1):(1,0),
             (1,0):(0,-1),
             (0,-1):(-1,0),
            }
result = [[0 for _ in range(len(A[0]))] for _ in range(len(A))]
count = 0
direction = (0,1)
now = [0,0]
while count <= len(A)*len(A[0])-1:
    move(sorting, result, count, now)
    count+=1
    try:
        result[now[0] + direction[0]][now[1] + direction[1]] #try if there's index error
    except:
        direction = directions[direction]
        now[0] += direction[0] #when you do such thing like now + direction when you turn
        now[1] += direction[1] #it's direction it works like this (tuple,tuple) += (tup, tup) ---->(tuple,tuple, tup, tup)
                               #concatenating :( soooooooooo ssssssaaaaadddddd
        continue
    if result[now[0] + direction[0]][now[1] + direction[1]] != 0: #if there's already a value
        direction = directions[direction]
        now[0] += direction[0] #turn it's direction
        now[1] += direction[1]

        continue
    else:
        now[0] += direction[0] 
        now[1] += direction[1]


print("\n".join(map(str, (result))))