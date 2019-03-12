# Dream vacation

responses = {}
polling_active = True

while polling_active:
    name = input("what's your name? ")
    response = input("where would you like to go? ")
    
    responses[name] = response
    
    repeat = input("would you like to let another person respond? ")
    if repeat == 'no':
        polling_active = False

# showing results
print("\n--- Poll Results ---")
for name, response in responses.items():
    print(f"{name.title()} want to go {response}.")