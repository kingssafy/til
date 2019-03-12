import json

filename = 'number.json'

with open(filename, 'w') as f_object:
    favorite_number = input("Tell me your favorite number")
    json.dump(favorite_number, f_object)

