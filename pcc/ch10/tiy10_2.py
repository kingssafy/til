file_name = "learned.txt"
with open(file_name) as file_object:
    a = file_object.readlines()

for line in a:
    print(line.replace("Python", "C"), end="")
