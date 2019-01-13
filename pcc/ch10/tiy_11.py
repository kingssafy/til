file_name = "learned.txt"
with open(file_name) as file_object:
    lines = file_object.readlines()

for i in range(3):
    for line in lines:
        print(line, end="")

