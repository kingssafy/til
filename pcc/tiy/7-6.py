# Movie Tickets
# age = 1
# fee = 0
# prompt = "\nEnter your age and we'll tell you the price"
# prompt += "\n(when you're done please enter 0 to exit): "

# while True:
#     age = input(prompt)
#     if len(age) != 0:
#         age = int(age)
#         if age == 0:
#             break
#         elif age < 3:
#             fee = 0
#         elif age < 12:
#             fee = 10
#         else:
#             fee = 15
#         print(f"Your fee is {fee}.")


age = 1
fee = 0
count = 0

prompt = "\nEnter your age and we'll tell you the price"
prompt += "\n(when you're done please enter 0 to exit): "

while count < 5:
    age = input(prompt)
    count += 1
    if len(age) != 0:
        age = int(age)
        if age == 0:
            break
        elif age < 3:
            fee = 0
        elif age < 12:
            fee = 10
        else:
            fee = 15
        print(f"Your fee is {fee}.")
