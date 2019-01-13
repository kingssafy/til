foods = ('rice', 'noodle', 'fried', 'steamed', 'boiled', 'grilled')

for food in foods:
    print(food)

#foods[2] = 'ramen' #TypeError: 'tuple' object does not support item assignment

foods = ('rice', 'noodle', 'fried', 'steamed', 'frozen', 'stews')

for food in foods:
    print(food)
print(type(foods))