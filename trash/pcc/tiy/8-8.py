def make_album(name, title):
 
    return {'artist_name': name, 'album_title': title}

while True:
    print('press q to quit')
    aname = input("artist_name: ")
    if aname == 'q':
        break
    atitle = input("album_title: ")
    if atitle == 'q':
        break
    myalbum = make_album(aname, atitle)
    print(myalbum)