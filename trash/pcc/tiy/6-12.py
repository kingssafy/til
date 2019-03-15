cities = {
    'seoul': {
        'country': 'korea',
        'population': 20,
        'fact': 'complex',
    },
    
    'busan': {
        'country': 'korea',
        'popluation': 2,
        'fact': 'fish',
    },

    'newyork': {
        'country': 'usa',
        'poluation': 8,
        'fact': 'rich'
    },
}

for city, info in cities.items():
    print(f"{city.title()}'s infos:")
    for key, value in info.items():
        print("\t" + key + ": " + str(value))