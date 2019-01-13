def build_profile(first, last, **user_info):
        """build a dictionary containing every thing we know  about a user."""
        profile ={}
        profile['first_name'] = first
        profile['last_name'] = last
        for key, value in user_info.items():
                profile[key] = value
        return profile

user_profile = build_profile('eric', 'kim', country = 'korea', sex = 'male',
does_love_counts = 'yes')
print(user_profile)