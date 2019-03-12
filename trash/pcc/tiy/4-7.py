#Threes: Make a list of multiples of 3 from 3 to 30
numbers = [value * 3 for value in range(1, 11)]
for number in numbers:
    print(number)

numbers = list(range(3,31,3))
for number in numbers:
    print(number)