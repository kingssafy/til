names = ['mozart', 'beethoven', 'bach']
for name in names:
    message = f'{name.title()}, i would like to invite you to chicken dinner!'
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