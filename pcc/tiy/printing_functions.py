def print_models(unprinted_designs, completed_models):
    # Simulate printing each design, until non are left.
    # Move each design to completed_models after printing
    while unprinted_designs:
        current_design = unprinted_designs.pop()
        # Simulate creating a 3D print from the design.
        print("Printing model: " + current_design)
        completed_models.append(current_design)
def show_completed_models(completed_models):
    #Display all completed models.
    print('\nTHE FOLLOWING MODELS HAVE BEEN PRINTED: ')
    for completed_model in completed_models:
        print(completed_model)
