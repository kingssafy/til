current_users = ['admin', 'kim', 'lee', 'park' , 'choi']
new_users = ['jung', 'Admin', 'kim', 'no', 'kang']

for new_user in new_users:
    if new_user.lower() in current_users: #comparison is case insensitive 
                                          #by string.lower() method
        print("enter a new username")
    else:
        print(f"{new_user} is available")
