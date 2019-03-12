print("Give me two numbers, and I'll divide them.")
print("Enter 'q' to quit.")

while True:
    first_number = input("\nFirst Number: ")
    if first_number == 'q':
        break
    second_number = input("\nSecond Number: ")
    try:
        answer = int(first_number)/int(second_number)
    except: # You can use to except ZeroDivisionError: to specify 
        print("You can't divide by 0!")
    else:
        print(answer)
