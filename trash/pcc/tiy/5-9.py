#usernames = ['admin', 'kim', 'lee', 'park', 'choi']
usernames = []
if usernames:
    for username in usernames:
        if username == 'admin':
            print(f"Hello {username}, would you like too see a status report?")
        else:
            print(f"Hello {username}, thank you for logging in again.")
else:
    print("We need to find some users!")