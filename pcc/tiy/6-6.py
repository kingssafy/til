favorite_languages = {
    'jen': 'python',
    'sarah': 'c',
    'edward': 'ruby',
    'phil': 'python', 
}

people = ['jen', 'sarah', 'bob', 'clara', 'edward', 'phil']

for person in people:
    if person in favorite_languages.keys():
        print(f"thank you for your reponding, {person}")
    else:
        print(f"{person}, please take the poll")