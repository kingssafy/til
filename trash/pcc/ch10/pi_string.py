file_name = "pi_million_digits.txt"
with open(file_name) as file_object:
    lines = file_object.readlines()

result = ""
for line in lines:
    result += line.strip()

birthday = input("Enter your birthday, in the form mmddyy: ")
if birthday in result:
    print("Your birthday appears in the first million digits of pi!")
else:
    print("Your birthday does not appear in the first million digits of pi.")
