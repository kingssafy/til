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
