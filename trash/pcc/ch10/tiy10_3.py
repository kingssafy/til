filename = "guest.txt"
user_name = input("Please enter your name: ")

with open(filename, "w") as fileobject:
    fileobject.write(f"{user_name}")
