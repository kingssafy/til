n = 5
x = 5
y = 6
doors = [1, 2, 6, 10, 3]
door_can_broke = 0
if x > y:
    print(len(doors))

else:
    for door in doors:
        if door <= x:
            door_can_broke += 1
    if door_can_broke / 2 == door_can_broke//2 :
        print(door_can_broke//2)
    else:
        print(door_can_broke//2+1)

#i solve this problem mathematically
#not gamical!!
#wanna solve this problem exhausitive searchillly
#Aceepted

#optimize
n = 5
x = 5
y = 6
doors = [1, 2, 6, 10, 3]
door_can_broke = 0
if x > y:
    print(len(doors))

else:
    doors.sort()
    while door_can_broke <= n-1 and doors[door_can_broke] <= x:
        door_can_broke +=1
    
    if door_can_broke / 2 == door_can_broke//2 :
        print(door_can_broke//2)
    else:
        print(door_can_broke//2+1)
#optimize but costs same