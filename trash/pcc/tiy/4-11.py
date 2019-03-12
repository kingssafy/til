pizzas = ['peperoni', 'combination', 'beefquesadia']

friend_pizzas = pizzas[:]

pizzas.append('double fondue')
friend_pizzas.append('rich gold')
print("my favorite pizzas are:")
for pizza in pizzas:
    print(pizza)
print("my friend's favorite pizzas are:")
for pizza in friend_pizzas:
    print(pizza)