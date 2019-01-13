file_names = ['cats.txt', 'dogs.txt', 'catrol.txt']


for file_name in file_names:
    try:
        with open(file_name) as f_obj:
            contents = f_obj.read()
    except FileNotFoundError:
        pass
    else:
        print(contents)

