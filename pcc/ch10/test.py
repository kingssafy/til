girls = ['jane', 'iu', 'mary']
boys = ['justin', 'david', 'kim']
names = ['Rick Sanchez', 'Morty Smith', 'Summer Smith']
first_name = []
for name in names:
    first_name.append(name.split()[0].lower())
print(first_name)
