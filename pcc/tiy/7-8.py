sandwich_orders = ['ham', 'cheese', 'beef', 'pork', 'sister']
finished_sandwiches = []

while sandwich_orders:
    current_sandwich = sandwich_orders.pop()
    finished_sandwiches.append(current_sandwich)
    print("I made your " + current_sandwich + " sandwich.")

print("\n---following sandwiches are finished---")
for sandwich in finished_sandwiches:
    print("\t" + sandwich + " sandwich.")
