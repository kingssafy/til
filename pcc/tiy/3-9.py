names = ['mozart', 'beethoven', 'bach']
for name in names:
    message = f'{name.title()}, i would like to invite you to chicken dinner! total : {len(names)}people' # use len() to print a message indicating the number of people you're inviting
    print(message)
message = f'{names.pop(1)} can`t make it'
print(message)
names.append('haydn')
for name in names:
    message = f'{name.title()}, i would like to invite you to chicken dinner!'
    print(message)
print('i just found bigger table')
names.insert(0,'mahler')
names.insert(2,'liszt')
names.append('chopin')
for name in names:
    message = f'{name.title()}, i would like to invite you to beef dinner!'
    print(message)
print('bigger dinner table is not available, and i only have space for two')

while len(names) != 2:
    popped = names.pop()
    print(f"sorry, you're eliminated {popped}")
for name in names:
    print(f"you're still alive {name}")
del names[0]
del names[0]
print(names)