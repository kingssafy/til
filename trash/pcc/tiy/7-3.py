number = input("Enter any number you want: ")
number = int(number)

if number % 10 == 0:
    print("The number " + str(number) + " is a multiple of 10.")
else:
    print("The number " + str(number) + " isn't a multiple of 10.")