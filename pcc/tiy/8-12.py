# Sandwiches
def sandwich_order(*toppings):
    print("We are making a sandwich with following toppings:")
    for topping in toppings:
        print(f"\t- {topping}")

sandwich_order("beef", "prok", "chicken")
sandwich_order("letus", "onion", "err")
