import json

filename = 'number.json'

with open(filename, 'r') as f_obj:
    favorite_number = json.load(f_obj)
    print(f"your favorite number is {favorite_number}.")
