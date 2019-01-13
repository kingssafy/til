def make_album(name, title):
 
    return {'artist_name': name, 'album_title': title}

a = make_album('avril lavigne', 'smile')
print(a)
print(type(a))