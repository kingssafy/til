with open('pi_digits.txt') as file_object:
    lines = file_object.readlines()

print(type(lines))
for line in lines:
    print(line.rstrip())

