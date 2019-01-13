pizza = 'peperoni'
print(pizza)
print("pizza != 'peperoni'", pizza == 'peperoni')
print("pizza != 'peperoni'", pizza != 'peperoni')
print()
pizza = 'Peperoni'
print(pizza)
print("pizza == 'peperoni'", pizza == 'peperoni')
print("pizza.lower() == 'peperoni'", pizza.lower() == 'peperoni')

#Numerical tests
age_0 = 19
age_1 = 17
print(age_0 == 19)
print(age_0 != 19)
print(age_0 > 18)
print(age_0 < 18)
print(age_0 <= 19)
print(age_0 >= 19)

#test using the 'and', 'or'
print((age_0 > 15) and (age_1 < 20))
print((age_0 < 18) or (age_1 < 18))

pizzas = ['beef', 'pork', 'peperoni']
print('peperoni' in pizzas)
print('bulgogi' not in pizzas)