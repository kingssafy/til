favorite_numbers = {
    'kim': [7, 12],
    'lee': [5, 7],
    'anthony': [13, 21],
    'christina': [20, 30],
    'economy': [1991, 2018],
}

for name, numbers in favorite_numbers.items():
    print("\n" + name.title() + ":")
    for number in numbers:
        print("\t" + str(number))