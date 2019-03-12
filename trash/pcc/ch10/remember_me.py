import json

def get_stored_username():
    """Get stored user name if available."""
    filename = 'username.json'

    try:
        with open(filename) as f_obj:
            username = json.load(f_obj)
    except FileNotFoundError:
        return None
    return username

def get_new_username():
    """prompt for a new username."""
    filename = 'username.json'
    with open(filename, 'w') as f_obj:
        username = input("What is your name?: ")
        json.dump(username,f_obj)
    return username

def greet_user():
    """Greet the user by name."""
    username = get_stored_username()
    if username:
        check = input(f"{username} is your name. correct? (y/n)")
        if check in 'Yy':
            print(f"Welcome back, {username}!.")
        else:
            username = get_new_username()
            
    else:
        username = get_new_username()
        print(f"We'll remember you when you come back, {username}!")



greet_user()
