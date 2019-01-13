#Common Words.

file_name = 'alice.txt'
target = 'the'

with open(file_name) as f_obj:
    contents = f_obj.read()

print(contents.lower().count(target))
