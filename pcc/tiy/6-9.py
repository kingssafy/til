favorite_places = {
    'kim':  ['los angeles', 'japan', 'korea'],
    'park': ['paris', 'spain', 'cheongju'],
    'kang': ['busan', 'park', 'gym'],
}

for name, places in favorite_places.items():
    print(name + ": ")
    for place in places:
        print("\t" + place)
