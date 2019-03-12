sandwich_orders = ['ham', 'pastrami', 'pastrami', 'pork', 'pastrami']
finished_sandwiches = []
run_out = ['pastrami']

if run_out:
    i = 0
    if i < len(run_out):
        print("\ndeli has run out of " + run_out[i] + "\n")
        while run_out[i] in sandwich_orders:
            sandwich_orders.remove(run_out[i])
        i += 1


while sandwich_orders:
    current_sandwich = sandwich_orders.pop()
    finished_sandwiches.append(current_sandwich)
    print("I made your " + current_sandwich + " sandwich.")

print("\n---following sandwiches are finished---")
for sandwich in finished_sandwiches:
    print("\t" + sandwich + " sandwich.")
