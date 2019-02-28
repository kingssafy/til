dishes = input()
before = False
height = 0
for dish in dishes:
    if dish == before:
        height += 5
    else:
        height += 10
    before = dish
print(height)
